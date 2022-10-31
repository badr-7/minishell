/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_creat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:58:13 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/31 10:34:07 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char **av_creat(t_cmd *list)
{
    char **av;
    int size;

    size = cmd_size(list);
    av = malloc(sizeof(char *) * size + 1);
    while(list)
    {
        if (list->wc)
        {
            while(list->wc)
            {
                list->wc = list->wc->next;
            }
        }
        list = list->next;
    }
}