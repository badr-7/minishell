/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:45:02 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/03 13:25:10 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	lex_init(char *s)
{
	t_lexer	lexer;

	lexer.full_str = s;
	lexer.str = s;
	lexer.prev_type = t_init(NULL, 0, NULL);
	return (lexer);
}
