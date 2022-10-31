/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:43:36 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/31 09:56:33 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int  av_size(char **av)
{
    int i;

    i = 0;
    if(!av)
        return(0);
    while(*av++)
        i++;
    return(i);
}

t_parser_node   *node_create(char **av, t_rdr_node *rdrlist, t_token_type tp)
{
    t_parser_node   *node;

    node = malloc(sizeof(t_parser_node));
    node->av = av;
    node->ac = av_size(av);
    node->type = tp;
    node->rdrlst = rdrlist;
    node->right = NULL;
    node->left = NULL;
}