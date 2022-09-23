/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:27:05 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/23 17:39:35 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "./libft.h"

t_token	lex_search(t_lexer	lexer)
{
	t_token	token;

	token = token_cmpr(&lexer, "|", PIPE);
	if (token.type == ERROR)
		token = token_cmpr(&lexer, "<", RD_IN);
	if (token.type == ERROR)
		token = token_cmpr(&lexer, ">", RD_OUT);
	if (token.type == ERROR)
		token = token_cmpr(&lexer, "<<", HERDOC);
	if (token.type == ERROR)
		token = token_cmpr(&lexer, ">>", RD_APP);
	if (token.type == ERROR)
		token = token_cmpr(&lexer, "(", LEFT_P);
	if (token.type == ERROR)
		token = token_cmpr(&lexer, ")", RIGHT_P);
}

t_token	string_collect(char	*s)
{
	t_token	token;
	int		mode;
	int		i;
	int		len;

	mode = 0;
	len = 0;
	i = ft_strlen(META_C);
	while (*s && (mode != 0 || (!ft_strncmp(*s, META_C, i))))
	{
		mode = change_mode(*s);
		len++;
		s++;
	}
	if (!len)
		return (t_init(ERROR, 0, NULL));
	if (mode != 0 && *s == '\0')
		return (t_init(ERROR, 0, NULL));
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
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}
