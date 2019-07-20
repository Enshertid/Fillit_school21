# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 19:26:20 by ymanilow          #+#    #+#              #
#    Updated: 2019/07/17 11:41:28 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	fillit.c				\
		ft_list_add_to_end.c	\
		ft_list_new.c			\
		input.c					\
		includes/libft/libft.a

INCLUDES =	-Iincludes					\
			-Iincludes/libft/includes

all: $(NAME)

$(NAME):
	@clear
	@make -C includes/libft
	@gcc -Wall -Wextra -Werror $(SRCS) $(INCLUDES) -o fillit

clean:
	@make clean -C includes/libft
	@rm -Rf *.o

fclean: clean
	@make fclean -C includes/libft
	@rm $(NAME)

f: fclean

re: fclean all
