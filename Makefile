# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 19:26:20 by ymanilow          #+#    #+#              #
#    Updated: 2019/07/20 14:09:44 by dbendu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

SRCS =	fillit.c				\
		ft_list_add_to_end.c	\
		ft_list_new.c			\
		input.c

HEADERS =	-Iincludes			\
			-Ilibft/includes

OBJS =	fillit.o				\
		ft_list_add_to_end.o	\
		ft_list_new.o			\
		input.o					\
		libft/libft.a




all: $(NAME)


$(NAME):
	@make -C libft
	@gcc -Wall -Wextra -Werror -c $(SRCS) $(HEADERS)
	@gcc $(OBJS) -o $(NAME)


clean:
	@make clean -C libft
	@rm $(OBJS)


fclean: clean
	@rm $(NAME)


re: fclean all


f: fclean
