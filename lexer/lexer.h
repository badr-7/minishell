/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:22:46 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/13 16:25:43 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define DEF_SINGEL_Q -1
# define DEF_DOUBEL_Q -2

#include"../libft/libft.h"
#include"../env1/env.h"
#include <stdbool.h>


typedef enum token_type
{
	CHAR_NULL,
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

typedef struct s_wc_node
{
	char				*d_name;
	int					len;
	struct s_wc_node	*next;
}		t_wc_node;

typedef struct token
{
	int				len;
	char			*pos;
	t_wc_node		*wildcard;
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
	t_error	error;
}		t_lexer;

typedef struct s_glb_v
{
	t_env_node	*list;
}			t_glb_v;

extern t_glb_v glb_v;

int			change_mode(int i, char c);
char        *quote_def(char  *str);
t_wc_node	*lstlast_dir(t_wc_node *lst);
void	    lstadd_back_dir(t_wc_node **lst, t_wc_node *new_ld);
t_wc_node	*lstnew_dir(char *content, int   len);
t_token		t_init(t_token_type	_tp, int len, char *p);
t_token		lex_search(t_lexer	lexer);
t_lexer		*lex_init(char *s);
t_token		word_collect(t_lexer	lexer);
t_token		get_token(t_lexer lexer);
t_token		get_next_token(t_lexer	*lexer);
t_token		check_next_token(t_lexer	lexer, int i);
t_token 	lex_wildcard(t_lexer    lexer, int  i);
t_token		t_wc_init(t_token_type	type, int len, t_wc_node *p);
t_wc_node	*wc_ld_create(char *s);
t_token 	lex_var(t_lexer lexer, int i);
bool    	is_match(char *p, char *dir_n, int mode);
int			change_mode2(int i, char c);

#endif