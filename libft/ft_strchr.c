/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:16:19 by mel-hous          #+#    #+#             */
/*   Updated: 2021/11/09 10:43:43 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			dest = (char *)&str[i];
			return (dest);
		}
		i++;
	}
	if (str[i] == '\0' && c == '\0')
	{
		dest = (char *) &str[i];
		return (dest);
	}
	return (NULL);
}
