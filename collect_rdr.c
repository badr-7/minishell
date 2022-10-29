/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_rdr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:36:04 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/29 11:06:56 by mel-hous         ###   ########.fr       */
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

static char	*get_heredoc_filename(t_token t)
{
	static int	n = 0;
	char		*n_str;
	char		*delim;
	char		*f;
	bool		expand;

	expand = !ft_memchr(t.pos, DEF_SINGEL_Q, t.len);
	expand = (expand && !ft_memchr(t.pos, DEF_DOUBEL_Q, t.len));
	n_str = ft_itoa(n);
	delim = ft_substr(t.pos, 0, t.len);
	if (delim)
		remove_quotes_enc(delim);
	if (n_str)
		f = ft_strjoin("/tmp/minishell-heredoc-", n_str);
	free(n_str);
	if (!delim || !n_str || !f || read_heredoc(f, delim, expand))
	{
		perror("minishell");
		free(delim);
		free(f);
		return (NULL);
	}
	free(delim);
	n++;
	return (f);
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

t_rdr_node	*rdr_init(t_token_type type, t_token str)
{
	t_rdr_node	*rdr;

	rdr = malloc(sizeof(t_rdr_node));
	if (!rdr)
	{
		perror("minishell");
		return (NULL);
	}
	rdr->type = type;
	if (rdr->type == HERDOC)
		rdr->file = get_heredoc_filename(str);
	else
		rdr->file = get_filename(str);
	if (rdr->file)
		return (rdr);
	free(rdr);
	return (NULL);
}
