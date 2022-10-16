/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:47:27 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/06 10:48:21 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env_node	*lstlast(t_env_node *lst)
{
	if (!lst)
		return (0);
	while (!(lst->next == NULL))
		lst = lst->next;
	return (lst);
}


void	add_back(t_env_node **lst, t_env_node *new)
{
	t_env_node	*p;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = lstlast(*lst);
	p->next = new;
}

t_env_node	*new_node(char *content, char *name, int len)
{
	t_env_node	*s;

	s = (t_env_node *)malloc(sizeof(t_env_node));
	if (s == NULL)
		return (NULL);
	s->content = content;
    s->name = name;
    s->len = len;
	s->next = NULL;
	return (s);
}