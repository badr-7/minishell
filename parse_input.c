/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:05:53 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/26 16:33:34 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node	*parse_input(char *input)
{
	t_parser_node	*pipe_line;
	t_lexer			*lexer;

	// *pipe_line = malloc(sizeof(t_parser));
	lexer = lex_init(input);
	pipe_line = ft_pipe_line(lexer);
	
}
