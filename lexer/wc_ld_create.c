/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_ld_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:44:55 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/05 15:20:29 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_wc_node	*lstlast_dir(t_wc_node *lst)
{
	if (!lst)
		return (0);
	while (!(lst->next == NULL))
		lst = lst->next;
	return (lst);
}


void	lstadd_back_dir(t_wc_node **lst, t_wc_node *new)
{
	t_wc_node	*p;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = lstlast_dir(*lst);
	p->next = new;
}

t_wc_node	*lstnew_dir(char *content, int   len)
{
	t_wc_node	*s;

	s = (t_wc_node *)malloc(sizeof(t_wc_node));
	if (s == NULL)
		return (NULL);
	s->d_name = content;
    s->len = len;
	s->next = NULL;
	return (s);
}

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