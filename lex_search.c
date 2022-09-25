/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:27:05 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/25 15:45:57 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "./libft.h"

t_token	word_collect(t_lexer *lexer)
{
	t_token	token;
	int		mode;
	int		len;
	char	*s;

	mode = 0;
	s = lexer->str;
	len = 0;
	while (*s && (mode != 0 || (!ft_strncmp(*s, " \t\n|&()<>", 9))))
	{
		mode = change_mode(*s);
		len++;
		s++;
	}
	if (!len)
		return (t_init(ERROR, 0, NULL));
	if (mode != 0 && *s == '\0')
		return (t_init(ERROR, 0, NULL));
	return (t_init(WORD, len, lexer->str));
}

t_token	t_init(t_token_type	type, int len, char *p)
{
	t_token	token;

	token.type = type;
	token.pos = p;
	token.len = len;
	return (token);
}

t_token	token_cmpr(t_lexer	*lexer, const char	*symbole, t_token_type type)
{
	int	i;

	i = ft_strlen(symbole);
	if (ft_strncmp(lexer->str, symbole, i))
		return (t_init(ERROR, 0, NULL));
	return (t_init(type, i, lexer->str));
}

int	change_mode(char c)
{
	if (c == 39)
		return (1);
	if (c == 34)
		return (2);
	return (0);
}
