/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:47 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/07 14:33:28 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token lex_var(t_lexer lexer, int i)
{
    char *s;
    t_env_node  *node;

    if (lexer.str[0] == '$')  
    {
        printf("i = %d\n", i);
        s = ft_substr(lexer.str, 1 , i+1);
        node = env_find(glb_v.list, s, i - 1);
        if (!node)
            return (t_init(WORD, i, lexer.str));
        return (t_init(VAR, i , node->content));
    }
    return (t_init(WORD, i, lexer.str));
}