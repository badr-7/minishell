/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:15:14 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/03 14:42:31 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    node_del(t_parser_node  **node)
{
    t_parser_node   *tmp;
    tmp = *node;
    if (tmp)
    {
        node_del(&tmp->left);
        node_del(&tmp->right);

    }
    
}