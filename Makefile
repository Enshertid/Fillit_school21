all:
	@clear
	@gcc -Wall -Wextra -Werror -Ilibft/includes main.c input.c fillit.c libft/libft.a
	@./a.out
