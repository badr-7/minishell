/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_q.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:45:20 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/01 14:59:48 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"

char    *remove_quotes_enc(char *start)
{
    char    *s;
    int    n;

    s = start;
    n = strlen(s) + 1;
    while (*s)
    {
        if (*s == DEF_SINGEL_Q || *s == DEF_DOUBEL_Q)
            ft_memmove(s, s + 1, n - 1);
        else
            s++;
        n--;
    }
    return (start);
}