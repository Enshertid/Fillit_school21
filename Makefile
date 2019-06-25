all:
	@clear
	@gcc -Wall -Wextra -Werror *.c libft.a
	@./a.out