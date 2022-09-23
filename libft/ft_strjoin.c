/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:01:06 by mel-hous          #+#    #+#             */
/*   Updated: 2021/11/13 20:02:03 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		len;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	len = l1 + l2;
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_memmove(s, s1, l1);
	ft_memmove((s + l1), s2, l2);
	s[len] = '\0';
	return (s);
}
