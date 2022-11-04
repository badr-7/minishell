/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:23 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/04 14:27:04 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	rdr_addback(t_rdr_node **lst, t_rdr_node *new)
{
	t_rdr_node	*p;

    p = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (!(p->next == NULL))
		p = p->next;
	p->next = new;
}