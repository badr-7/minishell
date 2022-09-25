/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:08:59 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/25 13:04:13 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct token
{
	int				len;
	char			*pos;
	t_token_type	type;
}			t_token;

typedef enum token_type
{
	RD_IN,
	RD_OUT,
	HERDOC,
	RD_APP,
	PIPE,
	WORD,
	ERROR,
}		t_token_type;
typedef enum s_error
{
	SYNTAX_ERR,
	ENDOFFILE_ERR,
}		t_error;

typedef struct s_lexer
{
	char	*full_str;
	char	*str;
	int		pos;
	t_error	error;
}		t_lexer;

int		change_mode(char c);
t_token	token_cmpr(t_lexer	*lexer, const char	*symbole, t_token_type type);
t_token	t_init(t_token_type	type, int len, char *p);
t_token	lex_search(t_lexer	lexer);
t_lexer	lex_init(char *s);
t_token	word_collect(t_lexer *lexer);
t_token	get_token(t_lexer	*lexer);

#endif