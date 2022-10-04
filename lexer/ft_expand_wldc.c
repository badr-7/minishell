/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wldc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:07:17 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/04 15:55:34 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token lex_wildcard(t_lexer    lexer, int  i)
{
    char			*s;
	int				len;
	DIR 			*dp;
    struct dirent	*dirp;
	t_list			*list;
	
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
	if (!(dp = opendir(".")))
		rturn(NULL);
	dirp = readdir(dp);
	while(dirp)
	{
		ft_lstadd_back(&list, ft_lstnew(dirp->d_name));
		dirp = readdir(dp);
	}
	return (t_WC_init(WLDC, len, list));
}