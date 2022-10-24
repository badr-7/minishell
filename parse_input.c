/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:05:53 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/17 14:51:58 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node	*parse_input(t_lexer *lexer)
{
	t_parser_node	*pipeline;
	t_token			token;

	pipeline = ft_pipeline(lexer);
	if (!pipeline || pipeline->match_failed == -1)
		return (pipeline);
	token = get_next_token(lexer);
	if (token.type != END)
	{
		ft_putstr_fd( "minishel: syntax error: unexpected end of file\n", 2);
		 node_tree_clear(&pipeline);
	}
	return (pipeline);
}
