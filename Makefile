1:
	@clear
	@cd libft && make && make clean && mv libft.a ../ && cd ..
	@gcc -Wall -Werror -Wextra -Ilibft/includes main.c input.c shape.c solve1.c libft.a -o fillit

2:
	@clear
	@cd libft && make && make clean && mv libft.a ../ && cd ..
	@gcc -Wall -Werror -Wextra -Ilibft/includes main.c input.c shape.c solve2.c libft.a -o fillit

d:
	@clear
	@gcc -g -Wall -Werror -Wextra -Ilibft/includes *.c libft.a -o fillit

c:
	@clear
	@gcc -Wall -Werror -Wextra -Ilibft/includes *.c libft.a -o fillit
	@./fillit file.txt
