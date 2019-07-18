/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:56:20 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/14 14:56:21 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdio.h"

#include "libft.h"

#include "shape.h"
#include "input.h"
#include "solve.h"

void	error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

 int	main(int argc, const char * const *argv)
{
	int		fd;
	t_shape *shapes;
	char	**map;

	if (argc != 2)
	{
		write(1, "Only one file should be in arguments.\n", 39);
		write(1, "Example: fillit /*path*/filename\n", 34);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error();
	shapes = get_shapes(fd);
	map = solve(shapes);
	for (size_t i = 0; map[i]; ++i)
		ft_putstr(map[i]);
	free(map[0]);
	free(map);
	ft_shapeclear(&shapes);
	return (0);
}
