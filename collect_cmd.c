/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:45:13 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/26 16:55:26 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node   *collect_cmd(t_lexer *lexer)
{
    t_list	*elem;
	t_token	token;

	token = get_token(lexer);	
	if (token.type == WORD)
	{
		elem = ft_lstnew(ft_substr(lexer->str, 0, token.len));
		while(token.type == WORD)
		{
			
		}
	}
	
}