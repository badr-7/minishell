# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:32:30 by mel-hous          #+#    #+#              #
#    Updated: 2022/10/07 14:24:21 by mel-hous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADR = parser.h

NAME = parser.a

CC = gcc

CFLAGS = -Wextra -Wall -Werror -g -fsanitize=adress

SRC = 	lexer/get_next_token.c 
		lexer/get_token.c
		lexer/lex_create.c
		lexer/lex_search.c
		check_pipe.c
		collect_cmd.c
		ft_pipe_line.c
		parse_input.c 