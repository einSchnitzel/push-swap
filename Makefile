# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 15:58:08 by smetzler          #+#    #+#              #
#    Updated: 2021/11/07 16:11:26 by smetzler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap
FLAGS = -Werror -Wextra -Wall
SRC=

SRC=
INCLUDE=

${NAME}:
	${CC} ${CFLAGS} -c ${SRC}
	ar rc ${NAME} *.o

all:
	${NAME} ./libft/libft.a

clean:
	@make -C libft/ clean
	@echo ""

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all