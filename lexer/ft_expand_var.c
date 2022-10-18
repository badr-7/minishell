/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:47 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/18 17:23:50 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


void    sigle_q_handling(t_lexer lexer ,  t_env_node  *node)
{
    int     mode;
    char    *s;
    char    *dest;
    int     b;
    
      mode = 0;
    if(sigq_count(lexer.str, b))
    {
        s = ft_substr(lexer.str, jump_sinq(lexer.str, b) , collect_s(lexer.str, b) - jump_sinq(lexer.str, b));
        printf("s = %s\n", s);
        dest = expand(s,0 , node);
    }
    mode = change_mode(mode, lexer.str[b++]);
    // printf("mode = %d\nstr[b] = %c\n",mode, lexer.str[b]);
    while(mode != 0)
        mode =  change_mode(mode, lexer.str[b++]);
}

int    jump_sinq(char *str, int i)
{
    while(str[i] == 39)
        i++;
    return(i);
}

int    collect_s(char *str, int i)
{
    while(str[i] != 39)
        i++;
    return (i);
}

bool    sigq_count(char *str,int  i)
{
    int j;

    j = 0;
    while(str[i] &&  (ft_strchr(" \t\n|&()<>\"", str[i])))
    {
        if(str[i] == 39)
            j++;
        i++;
    }
    if(j % 4 == 0)
        return(true);
    else
        return(false);
}

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
        if(str[i] == '$' || str[i + 1] == '\0' || str[i + 1] == '"' || str[i + 1] == ' ')
        {
            ft_exand_utils(&i, &j, &b, str);
            if ((node = env_find(glb_v.list, ft_substr(str, b + 1 , j - b), -1)))
                if (dest == NULL)
                    dest = node->content;
                else
                    dest = ft_strjoin(dest, node->content);
            else
                if(!dest)
                    dest = ft_strdup("");
                else
                    continue ;
        }
    }
    return(dest);
}
t_token lex_var(t_lexer lexer, int i)
{
    char *dest;
    t_env_node  *node;
    int         j;
    int         b;

    dest = NULL;
    j = 0;
    if (lexer.prev_type.type == HERDOC)
        return (t_init(WORD, i, lexer.str));
    while (lexer.str[j] && lexer.str[j] == '"')
        j++;
    b = j;
    while (lexer.str[b] && b < i)
    {
        if(!(ft_strchr(" $\'\t\n|&()<>", lexer.str[b])))
            break;
        b++;
    }
    if (lexer.str[b] == 39)
    {
       
    }
    // if (b > j)
    //      dest = ft_substr(lexer.str, j , b - j);
    printf("b = %d\nj = %d\ndest = %s\n", b, j,dest);
    if (lexer.str[b] == '$')
    {
        if(dest)
            dest = ft_strjoin(dest, expand(lexer.str, j, node));
        else
            dest = expand(lexer.str, j, node);
        if(dest)
            return (t_init(VAR, i , dest));
    }
    free(dest);
    return (t_init(WORD, i, lexer.str));
}