/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:44:36 by dbendu            #+#    #+#             */
/*   Updated: 2019/06/25 20:44:39 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "fcntl.h"

#include "fillit.h"
#include "input.h"

void	print(t_shape *shape)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((shape->points[0].x == i && shape->points[0].y == j) ||
				(shape->points[1].x == i && shape->points[1].y == j) ||
				(shape->points[2].x == i && shape->points[2].y == j) ||
				(shape->points[3].x == i && shape->points[3].y == j))
				write(1, "#", 1);
			else
				write(1, ".", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

int		main(void)
{
	int		fd;
	t_list	*shapes;
	t_list	*temp;

	if ((fd = open("file.txt", O_RDONLY)) < 1)
		error();
	shapes = processing_input(fd);
	close(fd);
	temp = shapes;
	while (shapes)
	{
		print((t_shape*)shapes->content);
		write(1, "\n", 1);
		shapes = shapes->next;
	}
	ft_lstclear(&temp);
	return (0);
}
