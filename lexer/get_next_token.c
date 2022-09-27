/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:41:49 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/27 11:08:53 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	get_next_token(t_lexer	*lexer)
{
	t_token token;
	int	i;

	i = 0;
	token = get_token(lexer);
	lexer->pos += token.len;
	lexer->str += token.len;
	while (lexer->full_str[lexer->pos] == 32)
	{
		lexer->pos++;
		i++;
	}
	lexer->str += i;
	return (token);
}
