/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:45:13 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/13 15:08:26 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node   *collect_cmd(t_lexer *lexer)
{
    t_list	**elem;
	t_token	token;

	token = get_token(*lexer);
	while (token.type != ERROR || token.type != PIPE || token.type != END)
	{
		get_next_token(lexer);
		elem = cmd_ccomponents(lexer);
	}
	
	return (elem);
}