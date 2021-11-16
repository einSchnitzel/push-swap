# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 15:58:08 by smetzler          #+#    #+#              #
#    Updated: 2021/11/16 16:28:20 by smetzler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap
FLAGS = -Werror -Wextra -Wall
OPPATH = src/operations

SRC = src/main.c src/inputcheckers.c src/libftutils.c src/makelst.c src/free.c \
		$(OPPATH)/push_op.c $(OPPATH)/rotate_op.c $(OPPATH)/rrotate_op.c\
		#$(OPPATH)/swap_op.c

$(NAME):	
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

all:
	${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	$(CC) $(FLAGS) -o $(NAME) $(SRC)