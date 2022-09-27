/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:14:02 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/26 15:51:22 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include "libft/libft.h"

typedef struct parser
{
	char					**av;
	int						ac;
	int						match_failed;
	t_parser_node			*left;
	t_parser_node			*right;
	t_token_type			type;
}			t_parser_node;

t_parser_node   *check_pipe(t_lexer  *lexer);
t_parser_node   *ft_pipe_line(t_lexer   *lexer);
t_parser_node   *collect_cmd(t_lexer *lexer);
t_parser_node	*parse_input(t_lexer lexer);

#endif