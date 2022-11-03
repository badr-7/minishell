/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:40:53 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/03 15:18:58 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd *cmd_ccomponents(t_lexer *lexer, t_cmd	*cmd, t_rdr_node	*rdr)
{
	t_token	token;

    token = get_next_token(lexer);
	while(token.type != END || token.type != ERROR ||
		token.type != PIPE )
	{
		if (token.type == WORD)
			cmd_addback(cmd, ft_new_cmd(ft_substr(lexer->str, 0, token.len), NULL));
		else if(token.type == VAR)
			cmd_addback(cmd, ft_new_cmd(token.pos, NULL));
		else if(token.type == WLDC)
			cmd_addback(cmd, ft_new_cmd(token.pos, token.wildcard));
		else if(token.type == RD_APP || token.type == RD_IN ||
				token.type == RD_OUT || token.type == HERDOC)
			rdr_addback(&rdr, collect_rdr(lexer, rdr));
		token = get_next_token(lexer);
	}
	return (cmd);
}