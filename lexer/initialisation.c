/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:45:02 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/06 11:01:02 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	lex_init(char *s)
{
	t_lexer	lexer;

	lexer.full_str = s;
	lexer.str = s;
	lexer.prev_type = t_init(NULL, 0, NULL);
	return (lexer);
}

t_token	t_init(t_token_type	type, int len, char *p)
{
	t_token	tok;

	tok.type = type;
	tok.pos = p;
	tok.len = len;
	tok.wildcard = NULL;
	return (tok);
}

t_token	t_wc_init(t_token_type	type, int len, t_list *p)
{
	t_token	tok;

	tok.type = type;
	tok.pos = NULL;
	tok.len = len;
	tok.wildcard = p;
	return (tok);
}