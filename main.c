/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:44:09 by user              #+#    #+#             */
/*   Updated: 2019/07/20 09:55:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void error(void)
{
	write(1, "error\n", 6);
	exit(0);
}


int			main(int argc, const char * const *argv)
{
	int		fd;
	char	**map;
	t_shape	*shapes;

	if (argc != 2)
	{
		write(1, "One file must been in arguments.\n", 34);
		write(1, "Example: ./fillit file_name\n", 29);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error();
	shapes = NULL;
	ft_input(fd, &shapes);
	map = ft_do_fillit(shapes);
	return (0);
}