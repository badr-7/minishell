/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_match_enc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:16:50 by syakoubi          #+#    #+#             */
/*   Updated: 2022/10/06 16:36:30 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <stdbool.h>

static bool    match_rec(const char *p, const char *s, t_quote_mode mode)
{
    const char    *s_start = s;

    while (true)
    {
        while (*p == ENCODED_SINGLEQ || *p == ENCODED_DOUBLEQ)
            mode = switch_quote_mode_enc(mode, *p++);
        if (*p == '\0')
            return (*s == '\0');
        else if (mode == UNQUOTED && *p == '*')
        {
            while (*p == ENCODED_SINGLEQ || *p == ENCODED_DOUBLEQ
                || (mode == UNQUOTED && *p == '*'))
                mode = switch_quote_mode_enc(mode, *p++);
            if ((*s == '.' && s == s_start))
                return (false);
            if (*p == '\0')
                return (true);
            while (*s != '\0')
                if (match_rec(p, s++, mode))
                    return (true);
            return (false);
        }
        else if (*p++ != *s++)
            return (false);
    }
}

bool	glob_match_enc(const char *p, const char *s)
{
	return (match_rec(p, s, UNQUOTED));
}
