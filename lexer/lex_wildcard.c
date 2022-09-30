/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_wildcard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:07:17 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/30 17:12:31 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token lex_wildcard(t_lexer    lexer, int  i)
{
    char	*s;
	int		len;
	
	len = 0;
	s = lexer.str;
	if(i > 0)
	{
		while(s[i] != 32)
			i--;
	}
	while(s[i++] != '\0' && ft_strchr(" \t\n|&()<>", s[i]))
        len++;
	return (t_init(WLDC, len, s));
}