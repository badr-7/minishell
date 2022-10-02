/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:27:05 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/02 11:12:10 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <unistd.h>
#include <string.h>

t_token	word_collect(t_lexer lexer)
{
	int		mode;
	int		len;
	int		i;
	char 	*s;

	i = 0;
	s = lexer.str;
	mode = 0;
	len = 0;
	while (s[i] != '\0' && (mode != 0 || (ft_strchr(" \t\n|&()<>", s[i]))))
	{
		// if (s[i] == '$')
		// 	return (lex_var(lexer, i));
		// if (s[i] == '*' && mode == 0)
		// 	return (lex_wildcard(lexer, i));
		mode = change_mode(*s);
		len++;
		i++;
	}
	if (!len)
		return (t_init(ERROR, 0, NULL));
	if (mode != 0 && s[i] == '\0')
		return (t_init(ERROR, 0, NULL));
	s = ft_expand_wldc(len, lexer);
	s = ft_expand_var(len, lexer);
	return (t_init(WORD, len, s));
}

t_token	t_init(t_token_type	type, int len, char *p)
{
	t_token	tok;

	tok.type = type;
	tok.pos = p;
	tok.len = len;
	return (tok);
}

int	change_mode(char c)
{
	if (c == 39)
		return (1);
	if (c == 34)
		return (2);
	return (0);
}
