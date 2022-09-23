/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:45:02 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/23 13:26:00 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "./libft.h"

t_lexer	lex_init(char *s)
{
	t_lexer	lexer;

	lexer.full_str = s;
	lexer.pos = s;
	lexer.pos = 0;
	return (lexer);
}
