/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_rdr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:36:04 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/01 14:44:12 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>

static int	write_heredoc_line(char *f, int fd, char *line, bool expand)
{
	char	*expanded;

	expanded = NULL;
	if (expand)
	{
		expanded = expand_params(line);
		if (!expanded)
		{
			close(fd);
			unlink(f);
			free(f);
			free(line);
			return (-1);
		}
		ft_putstr_fd(expanded, fd);
		ft_putchar_fd('\n', fd);
		free(expanded);
	}
	else
	{
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
	}
	return (0);
}

static int	read_heredoc(char *f, char *delim, bool expand)
{
	int		fd;
	char	*line;

	fd = open(f, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishel: ", 2);
		ft_putstr_fd(f, 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
		return (-1);
	}
	line = readline(">");
	while (line)
	{
		if (!strcmp(line, delim))
			break ;
		if (write_heredoc_line(f, fd, line, expand))
			return (-1);
		free(line);
		line = readline(">");
	}
	free(line);
	close(fd);
	return (0);
}

static char	*get_heredoc_filename(t_token t, char *delim)
{
	char		*file;
	static int	i = 0;
	bool		exp;
	char		*n_file;

	exp = !ft_memchr(t.pos, DEF_SINGEL_Q, t.len);
	exp = (exp && !ft_memchr(t.pos, DEF_DOUBEL_Q, t.len));
	n_file = ft_itoa(i);
	if (delim)
		remove_quotes_enc(delim);
	if (n_file)
		file = ft_strjoin("/tmp/minishell-heredoc-", n_file);
	free(n_file);
	if (!delim || !n_file || !file || read_heredoc(file, delim, exp))
	{
		perror("minishell");
		free(delim);
		free(file);
		return (NULL);
	}
	free(delim);
	i++;
	return (file);
}

static char	*get_filename(t_token token)
{
	t_list	*exp;
	char	*s;

	exp = expand_glob(token);
	if (!exp)
		return (NULL);
	if (ft_lstsize(exp) != 1)
	{
		ft_putstr_fd("minishell ", 2);
		ft_putnstr_fd(token.pos, token.len, 2);
		ft_putstr_fd(": ambiguous redirect", 2);
		ft_lstclear(&exp, free);
		return (NULL);
	}
	s = exp->content;
	ft_lstdelone(exp, NULL);
	return (s);
}

t_rdr_node	*collect_rdr(t_lexer	*lexer, t_rdr_node	*rdr)
{
	t_token		token;

	token = get_next_token(lexer);
	rdr = malloc(sizeof(t_rdr_node));
	if (!rdr)
	{
		perror("minishell");
		return (NULL);
	}
	rdr->type = lexer->prev_type.type;
	if (rdr->type == HERDOC)
		rdr->file = get_heredoc_filename(token, ft_substr(token.pos, 0, token.len));
	else
		rdr->file = get_filename(token);
	if (rdr->file)
		return (rdr);
	free(rdr);
	return (NULL);
}
