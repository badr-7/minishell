/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:14:02 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/31 09:56:41 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer/lexer.h"
# include "libft/libft.h"

# define MISSMATCH (void *)-1

typedef struct s_rdr_node
{
	t_token_type			type;
	char					*file;
	struct s_rdr_node				*next;
}			t_rdr_node;
typedef struct s_parser_node
{
	t_token_type			type;
	char					**av;
	int						ac;
	t_rdr_node				*rdrlst;
	struct s_parser_node	*left;
	struct s_parser_node	*right;
}			t_parser_node;

t_parser_node   *check_pipe(t_lexer  *lexer);
t_parser_node   *ft_pipe_line(t_lexer   *lexer);
t_parser_node   *collect_cmd(t_lexer *lexer);
t_parser_node	*parse(char *input);
t_parser_node	*parse_input(t_lexer *lexer);
t_cmd			*cmd_ccomponents(t_lexer *lexer, t_cmd	*cmd, t_rdr_node	*rdr);
t_parser_node   *node_create(char **av, t_rdr_node *rdrlist, t_token_type tp);

#endif