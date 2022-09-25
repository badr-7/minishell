/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:32:06 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/25 12:50:08 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	get_token(t_lexer	*lexer)
{
	t_token	token;

	token = token_cmpr(lexer, "|", PIPE);
	if (token.type == ERROR)
		token = token_cmpr(lexer, "<", RD_IN);
	if (token.type == ERROR)
		token = token_cmpr(lexer, ">", RD_OUT);
	if (token.type == ERROR)
		token = token_cmpr(lexer, "<<", HERDOC);
	if (token.type == ERROR)
		token = token_cmpr(lexer, ">>", RD_APP);
	if (token.type == ERROR)
		token = word_collect(lexer->str);
	return (token);
}
