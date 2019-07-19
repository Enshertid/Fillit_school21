# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 19:26:20 by ymanilow          #+#    #+#              #
#    Updated: 2019/07/19 15:42:57 by dbendu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS_C =	fillit.c			\
			input.c				\
			shape_operations.c	\
			map_operations.c	\
			main.c

all: $(NAME)

$(NAME):
	@clear
	@gcc -Wall -Wextra -Werror $(SRCS_C) -Ilibft/includes libft.a -o fillit

clean: 
	rm -Rf *.o

fclean: clean
	rm fillit

re: fclean all

d:
	@clear
	@gcc -g -Wall -Werror -Wextra -Ilibft/includes main.c  input.c shape_operations.c fillit.c map_operations.c libft.a -o fillit

c:
	@clear
	@gcc -g -Wall -Werror -Wextra -Ilibft/includes main.c  input.c shape_operations.c fillit.c map_operations.c libft.a -o fillit
	@./fillit file.txt