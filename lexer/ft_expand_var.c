/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:47 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/30 16:57:59 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token lex_var(t_lexer lexer, int i)
{
    t_token token;
    char    *s;
    int     len;
    
    len = 0;
    s = lexer.str;
    token = check_next_token(lexer, i);
    if (token.type == RD_OUT || token.type == RD_IN ||
        token.type == RD_APP || token.type == HERDOC)
	{
		printf("minishell: syntax error near unexpected token\n");
		exit(1);
	}
	while(s[i++] != '\0' && ft_strchr(" \t\n|&()<>", s[i]))
        len++;
    return (t_init(VAR, len, s));
}