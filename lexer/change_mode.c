/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:25:18 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/06 14:06:28 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	change_mode(int i, char c)
{
	if (c == 39)
    {
        if (i == 1)
            return (0);
		return (1);
    }
	if (c == 34)
	{
        if (i == 2)
            return (0);
		return (2);
    }
	return (0);
}
