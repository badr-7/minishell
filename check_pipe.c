/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:55:10 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/26 16:01:13 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node   *check_pipe(t_lexer  *lexer)
{
    t_parser_node   *pipe;
    t_parser_node   *cmd;
    t_token         token;

    token = get_token(lexer);
    if (token.type == PIPE)
    {
        cmd = collect_cmd(lexer);
        if (cmd->match_failed == -1)
        {
            ft_printf("ERROE");
        }
    }
}