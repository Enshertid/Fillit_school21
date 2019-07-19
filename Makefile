# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 19:26:20 by ymanilow          #+#    #+#              #
#    Updated: 2019/07/19 16:55:43 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS_C =	fillit.c			\
			input.c				\
			shape_operations.c	\
			map_operations.c	\
			main.c

LIB = -C libft

C_LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@make $(LIB)
	@gcc -Wall -Wextra -Werror -o fillit $(SRCS_C) -Iincludes -Ilibft/includes $(C_LIB)

clean:
	@rm -Rf *.o
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make f -C libft

re: fclean all
