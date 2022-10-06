/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:47 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/06 13:13:25 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token lex_var(t_lexer *lexer, int i, char **env)
{
    char *s;
    t_env_node  *node;

    i = 1;
    if (ft_isalnum(lexer->str[i]))  
    {
        while(lexer->str[i] && ft_isalnum(lexer->str[i]))
            i++;
        s = ft_substr(lexer->str, 1 , i);
        node = env_find(node, s, i);
        
        return (t_init(WORD, node->len, node->content));
    }
     return (t_init(WORD, node->len, node->content));
}