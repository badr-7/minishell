/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_ld_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:44:55 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/06 12:51:01 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <dirent.h>
#include <unistd.h>

t_wc_node  *wc_ld_create(void)
{
    DIR 			    *dp;
    struct dirent	    *dirp;
	t_wc_node			*_list;
    
    _list = NULL;
    dp = opendir(".");
    dirp = readdir(dp);
    while (dirp)
    {
        if(!ft_strncmp(dirp->d_name, ".", 1))
            dirp = readdir(dp);
        if(!ft_strncmp(dirp->d_name, "..", 2))
            dirp = readdir(dp);
        lstadd_back_dir(&_list, lstnew_dir(dirp->d_name, dirp->d_namlen));
        dirp = readdir(dp);
    }
    return(_list);
}