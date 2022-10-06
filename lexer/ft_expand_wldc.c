/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wldc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:07:17 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/06 13:03:46 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	wc_cont(char *s)
{
	int i;
	
	i = 0;
	while(*s)
	{
		if (*s == '*')
			i++;
		s++;
	}
	return(i);
}

t_token lex_wildcard(t_lexer    lexer, int  i)
{
    char			*s;
	int				len;
	t_wc_node		*list;
	
	list = NULL;
	len = 0;
	s = lexer.str;
	if(i > 0)
	{
		while(s[i] != 32)
			i--;
	}
	while(s[i++] != '\0' && ft_strchr(" \t\n|&()<>", s[i]))
        len++;
	s = ft_substr(lexer.str, i, len);
	list = wc_ld_create();
	
	
	return (t_wc_init(WLDC, len, list));
}