/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:27:05 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/06 11:00:56 by mel-hous         ###   ########.fr       */
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
		mode = change_mode(mode, *s);
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
