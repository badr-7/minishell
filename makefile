# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:32:30 by mel-hous          #+#    #+#              #
#    Updated: 2022/11/05 10:42:32 by mel-hous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADR = parser.h

NAME = parser.a

CC = gcc

INCLUDES := -I include -I$(HOME)/.homebrew/opt/readline/include

CFLAGS := $(INCLUDES) -Wall -Wextra -Werror

SRC = 	lexer/change_mode.c\
		lexer/check_next_token.c\
		lexer/ft_expand_var.c\
		lexer/ft_expand_wldc.c\
		lexer/get_next_token.c\
		lexer/get_token.c\
		lexer/initialisation.c\
		lexer/is_match.c\
		lexer/lex_search.c\
		lexer/quote_def.c\
		lexer/wc_ld_create.c\
		env1/create_env.c\
		env1/env_find.c\
		env1/env_ld.c\
		utils/cmd_list.c\
		utils/remove_q.c\
		utils/wc_ld.c\
		av_creat.c\
		check_pipe.c\
		cmd_components.c\
		collect_cmd.c\
		collect_rdr.c\
		ft_pipe_line.c\
		node_creat.c\
		node_del.c\
		parse_input.c\
		parser_start.c\
		rdr_addback.c\
		main.c\

OBJ = ${SRC:.c=.o}

$(NAME) : $(OBJ) $(HEADR)
			$(CC) $(CFLAGS) -o $(OBJ) $(libft.a)

libft.a : $(make) -C libft/