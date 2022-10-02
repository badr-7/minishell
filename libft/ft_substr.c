/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:19:11 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/02 12:52:02 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int beg, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (beg >= ft_strlen(s))
		return (ft_strdup(""));
	if (len == -1)
		len = ft_strlen(s) - (beg + 1);
	if (len > ft_strlen(&s[beg]))
		len = ft_strlen(&s[beg]);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[beg + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
