/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:30:20 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/03 09:50:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node   *ft_pipe_line(t_lexer   *lexer)
{
	t_parser_node	*cmd;
	t_parser_node	*pipe;

	cmd = collect_cmd(lexer);
	if (cmd && cmd == MISSMATCH)
	{
    	pipe = check_pipe(lexer);
		if (pipe == MISMATCH)
			return (cmd);
		if (pipe)
			pipe->left = cmd;
		else
			node_tree_clear(&cmd);
		return (pipe);
	}
	return (cmd);
}
