/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:22:46 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/01 18:14:26 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include "../libft/libft.h"

typedef enum token_type
{
	VAR,
	WLDC,
	TRUE,
	RD_IN,
	RD_OUT,
	HERDOC,
	RD_APP,
	PIPE,
	WORD,
	ERROR,
	END,
}		t_token_type;

typedef struct token
{
	int				len;
	char			*pos;
	t_token_type	type;
}			t_token;

typedef enum s_error
{
	SYNTAX_ERR,
	ENDOFFILE_ERR,
}		t_error;

typedef struct s_lexer
{
	char	*full_str;
	char	*str;
	t_token	prev_type;
	t_list	*wildcard;
	t_error	error;
}		t_lexer;

int		change_mode(char c);
t_token	t_init(t_token_type	type, int len, char *p);
t_token	lex_search(t_lexer	lexer);
t_lexer	lex_init(char *s);
t_token	word_collect(t_lexer	lexer);
t_token	get_token(t_lexer lexer);
t_token	get_next_token(t_lexer	*lexer);
t_token	check_next_token(t_lexer	lexer, int i);
t_token lex_var(t_lexer lexer, int i);
t_token lex_wildcard(t_lexer    lexer, int  i);

#endif