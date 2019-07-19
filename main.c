/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:56:15 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/19 16:06:58 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "fcntl.h"

#include "fillit.h"

int			main()
{
	int			fd;
	char		**map;
	t_shape		*shapes;
	unsigned	i;

	// if (ac != 2)
	// {
	// 	write(1, "Only one file must been in arguments.\n", 39);
	// 	write(1, "Example: ./fillit filename\n", 28);
	// 	return (0);
	// }
	if ((fd = open("/Users/ymanilow/Curcus42/fillit/file.txt", O_RDONLY)) == -1)
		error();
    ft_input(fd, &shapes);
	map = ft_do_fillit(shapes);
	i = 0 - 1;
	while (map[++i])
		ft_putstr(map[i]);
	ft_map_delete(map);
	ft_shapes_clear(&shapes);

	return (0);
}
