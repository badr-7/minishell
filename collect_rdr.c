/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_rdr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:36:04 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/05 09:45:21 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>
#include <string.h>

static int	write_heredoc_line(char *f, int fd, char *line, bool expand)
{
	char	*expanded;

	expanded = NULL;
	if (expand)
	{
		expanded = exp_var(&line);
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
		remove_q(delim);
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

static char	*get_filename(char *file)
{
	char	*s;
	t_wc_node	*wc_list;

	wc_list = wc_ld_create(file);
	if (!wc_list)
		return (NULL);
	if (wc_size(wc_list) != 1)
	{
		ft_putstr_fd("minishell ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ambiguous redirect", 2);
		wc_clear(&wc_list);
		return (NULL);
	}
	s = wc_list->d_name;
	// ft_lstdelone(wc_list, NULL);
	return (s);
}

t_rdr_node	*collect_rdr(t_lexer	*lexer, t_rdr_node	*rdr, t_token token)
{
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
		rdr->file = get_filename(ft_substr(token.pos, 0, token.len));
	if (rdr->file)
		return (rdr);
	free(rdr);
	return (NULL);
}
