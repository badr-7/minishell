/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:53:03 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/02 13:50:03 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"
# include <stddef.h>

typedef struct s_env_node{
    char				*name;
    char				*content;
	int					len;
	struct s_env_node	*next;
}			t_env_node;

t_env_node *create_env(char **env);
t_env_node *env_find(t_env_node *env, char  *s, int len);

#endif