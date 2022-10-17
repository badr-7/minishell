/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:47 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/17 17:55:51 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void    ft_exand_utils(int *i, int *j, int *b, char *str)
{
    *j = *i;
    if(str[*j] == '$')
        (*j)--;
    if(str[(*b) + 1] == '$')
        (*b)++;
}

char    *expand(char *str, int j, t_env_node  *node)
{
    int i;
    int b;
    char *dest;
    
    dest = NULL;
    i = j;
    while (str[i++] != '\0' && (ft_strchr(" \t\n|&()<>\"", str[i])))
    {
        b = j;
        if(str[i] == '$' || str[i + 1] == '\0' || str[i + 1] == '"')
        {
            ft_exand_utils(&i, &j, &b, str);
            if ((node = env_find(glb_v.list, ft_substr(str, b + 1 , j - b), -1)))
                if (dest == NULL)
                    dest = node->content;
                else
                    dest = ft_strjoin(dest, node->content);
            else
                if(!dest)
                    dest = ft_substr(str, b , (j - b) + 1);
                else
                    dest = ft_strjoin(dest, ft_substr(str, b , (j - b) + 1));
        }
    }
    return(dest);
}
t_token lex_var(t_lexer lexer, int i)
{
    char *str;
    char *dest = NULL;
    t_env_node  *node;
    
    int         j;
    int         b;
    
    str = lexer.str;
    j = 0;
    if (lexer.prev_type.type == HERDOC)
        return (t_init(WORD, i, str));
    while (str[j] && str[j] == '"')
        j++;
    if (str[j] == '$')
    {
        dest = expand(str, j, node);
        if(dest)
            return (t_init(VAR, i , dest));
    }
    return (t_init(WORD, i, str));
}