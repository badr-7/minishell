/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:41:49 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/16 12:01:55 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	get_next_token(t_lexer	*lexer)
{
	t_token token;
	int	i;

	i = 0;
	token = get_token(*lexer);
	//  printf("tok.str = %s\ntok.len = %d\n", token.pos, token.len);
	lexer->str += token.len;
	lexer->prev_type = token;
	//  if (token.wildcard)
	//     {
	// 	    while(token.wildcard->next != NULL)
	// 	    {
	// 		    printf("--%s\n", token.wildcard->d_name);
	// 	    	token.wildcard = token.wildcard->next;
    //         }
	//     }
	while (lexer->str[i] && lexer->str[i] == 32)
		i++;
	lexer->str += i;
	return (token);
}
