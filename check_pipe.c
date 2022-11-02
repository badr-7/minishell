/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:55:10 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/02 11:27:21 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node   *check_pipe(t_lexer  *lexer)
{
    t_parser_node   *pipe_line;
    t_parser_node   *pipe;
    t_token         token;

    token = get_next_token(lexer);
    if (token.type == PIPE)
    {
        pipe_line = ft_pipe_line(lexer);
        if (!pipe_line)
        {
            printf("ERROE");
            return (NULL);
        }
        return (pipe_line); 
    }
    else
        
}