/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:47 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/13 16:58:43 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token lex_var(t_lexer lexer, int i)
{
    char *s;
    t_env_node  *node;
    int         j;
    
    j = 0;
    while (lexer.str[j++] == '"')
    while (lexer.str[--i] == '"')
    // printf("%c\n", lexer.str[i]);
    if (lexer.str[j] == '$')
    {
        if (lexer.prev_type.type == HERDOC)
            return (t_init(WORD, i, lexer.str));
        s = ft_substr(lexer.str, j + 1 , i - 2);
        printf("%s\n", s);
        node = env_find(glb_v.list, s, -1);
        if (!node)
            return (t_init(WORD, i, lexer.str));
        return (t_init(VAR, i , node->content));
    }
    return (t_init(WORD, i, lexer.str));
}