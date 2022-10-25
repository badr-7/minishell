/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:38:13 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/25 14:56:18 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env_node *env_find(t_env_node *env, char  *s, int len)
{
    t_env_node *node;
    
    if (len == -1)
        len = ft_strlen(s);
    while(env)
    {
        if (len == env->len && !ft_strncmp(env->name, s, len))
        {
            node = env;
            return (node);
        }
        env = env->next;
    }
    return (NULL);
}

char *env_find2(t_env_node *env, char  *s, int len)
{   
    while(env)
    {
        if (!ft_strncmp(s, env->name, len))
            return (env->content);
        env = env->next;
    }
    return (NULL);
}