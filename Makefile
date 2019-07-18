# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 19:26:20 by ymanilow          #+#    #+#              #
#    Updated: 2019/07/18 16:34:00 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS_C = ./fillit.c \
		./ft_list_add_to_end.c\
		./ft_list_new.c \
		 ./input.c\
		 ./operation_with_map.c\

SRCS_H = ./libft/libft.a\

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o fillit $(SRCS_C)  $(SRCS_H)

clean: 
	rm -Rf fillit

fclean: clean
	rm -Rf *.h.*

re: fclean all
