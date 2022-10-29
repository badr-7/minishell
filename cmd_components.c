/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:40:53 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/29 16:00:51 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list **cmd_ccomponents(t_lexer *lexer)
{
    t_list	**elem;
	t_list	*new;
	t_token	token;

    token = get_token(lexer);
	*elem = ft_lstnew(ft_substr(lexer->str, 0, token.len));
	token = get_next_token(lexer);
	while(token.type == WORD || token.type == VAR ||
		token.type == WLDC)
	{
		new = ft_lstnew(ft_substr(lexer->str, 0, token.len));
		ft_lstadd_back(elem, new);
		token = get_next_token(lexer);
	}
	return (elem);
}