/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:19:11 by mel-hous          #+#    #+#             */
/*   Updated: 2021/11/16 08:28:58 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_substr(char const *s, unsigned int beg, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (beg >= ft_strlen(s))
		return (ft_strdup(""));
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
