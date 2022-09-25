/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:41:49 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/25 12:50:35 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	get_next_token(t_lexer	*lexer)
{
	int	i;

	i = 0;
	while (lexer->str == ' ')
		i++;
	lexer->pos += i;
	lexer->str += i;
	return (get_token(lexer));
}
