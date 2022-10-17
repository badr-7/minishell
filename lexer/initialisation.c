/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:45:02 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/17 11:41:08 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	*lex_init(char *s)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	// s = quote_def(s);
	lexer->full_str = s;
	lexer->str = s;
	lexer->prev_type = t_init(CHAR_NULL, 0, NULL);
	return (lexer);
}

t_token	t_init(t_token_type	_tp, int len, char *p)
{
	t_token	tok;

	tok.type = _tp;
	tok.pos = p;
	tok.len = len;
	tok.wildcard = NULL;
	return (tok);
}

t_token	t_wc_init(t_token_type	type, int len, t_wc_node *p)
{
	t_token	tok;

	tok.type = type;
	tok.pos = NULL;
	tok.len = len;
	tok.wildcard = p;
	return (tok);
}