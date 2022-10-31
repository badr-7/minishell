/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:27:05 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/31 08:37:28 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <unistd.h>
#include <string.h>

t_token	word_collect(t_lexer *lexer)
{
	int		mode;
	int		len;
	int		i;
	char 	*s;
	t_token	token;
	int		var;

	var = 0;
	i = 0;
	while (lexer->str[i] && lexer->str[i] == 32)
		i++;
	lexer->str += i;
	s = lexer->str;
	mode = 0;
	len = 0;
	// puts("a\n");
	while (s[len] != '\0' && (mode != 0 || (ft_strchr(" \t\n|&()<>", s[len]))))
	{
		mode = change_mode2(mode, s[len]);
		if(s[len] == '$' && mode != 1)
		{
			if(var == 2)
				var = 3;
			var = 1;
		}
		if((s[len] == '*' && var == 0))
			var = 2;
		len++;
	}
	if (!len)
		return (t_init(ERROR, 0, NULL));
	if (mode != 0 && s[i] == '\0')
		return (t_init(END, i, s));
	// s = ft_expand_wldc(len, lexer);
	if (var == 2 || var == 3)
	{
		token = lex_wildcard(*lexer, i);
		if (token.wildcard != NULL)
		{
			token.len = len;
			while(token.wildcard)
			{
				printf("--%s\n", token.wildcard->d_name);
				token.wildcard = token.wildcard->next;
			}
			return(token);
		}
	}
	// puts("a\n");
	// put_str(lexer.str,len);
	if(var == 1 || var == 3)
	{
    	// puts("1\n");
		token = lex_var(*lexer, len - 1);
		if(token.type == VAR)
		{
			token.len = len;
			return(token);
		}
	}
	return (t_init(WORD, len, s));
}

