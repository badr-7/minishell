/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:43:44 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/30 16:28:56 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_cmd	*ft_new_cmd(char *content, t_wc_node **list)
{
	t_cmd	*s;

	s = (t_cmd *)malloc(sizeof(t_cmd));
	if (s == NULL)
		return (NULL);
	s->word = content;
    s->wc = *list;
	s->next = NULL;
	return (s);
}

void	cmd_addback(t_cmd **lst, t_cmd *new)
{
	t_cmd	*p;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = cmd_lstlast(*lst);
	p->next = new;
}

t_cmd	*cmd_lstlast(t_cmd *lst)
{
	if (!lst)
		return (0);
	while (!(lst->next == NULL))
		lst = lst->next;
	return (lst);
}
