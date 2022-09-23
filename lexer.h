/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:08:59 by mel-hous          #+#    #+#             */
/*   Updated: 2022/09/23 15:54:03 by mel-hous         ###   ########.fr       */
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
	LEFT_P,
	RIGHT_P,
	STRING,
	ERROR,
}		t_token_type;

typedef struct lexer
{
	char	*full_str;
	char	*str;
	int		pos;
	t_error	error;
}		t_lexer;

typedef enum s_error
{
	SYNTAX_ERR,
	ERR,
}		t_error;

#endif