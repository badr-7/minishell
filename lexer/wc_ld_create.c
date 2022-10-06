/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_ld_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:44:55 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/06 10:27:40 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_wc_node  *wc_ld_create(void)
{
    DIR 			    *dp;
    struct dirent	    *dirp;
	t_wc_node			*list;
    
    list = NULL;
    dp = opendir(".");
    dirp = readdir(dp);
    while (dirp)
    {
        if(!ft_strncmp(dirp->d_name, ".", 1))
            dirp = readdir(dp);
        if(!ft_strncmp(dirp->d_name, "..", 2))
            dirp = readdir(dp);
        lstadd_back_dir(&list, lstnew_dir(dirp->d_name, dirp->d_namlen));
        dirp = readdir(dp);
    }
    return(list);
}