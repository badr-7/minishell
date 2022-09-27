/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:14:02 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/27 15:17:40 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer/lexer.h"
# include "libft/libft.h"

typedef struct s_parser_node
{
	char					**av;
	int						ac;
	int						match_failed;
	struct s_parser_node			*left;
	struct s_parser_node			*right;
	t_token_type			type;
}			t_parser_node;

t_parser_node   *check_pipe(t_lexer  *lexer);
t_parser_node   *ft_pipe_line(t_lexer   *lexer);
t_parser_node   *collect_cmd(t_lexer *lexer);
t_parser_node	*parse_input(t_lexer lexer);

#endif