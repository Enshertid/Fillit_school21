/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:03:12 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/19 16:23:34 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int				ft_fillit(char ***map, t_shape *shapes, size_t map_size)
{
	size_t x;
	size_t y;

	x = 0 - 1;
	while (++x < map_size && shapes)
	{
		y = 0 - 1;
		while (++y < map_size && shapes)
			if (ft_check_figure(*map, shapes, x * map_size + y, map_size))
			{
				ft_place_figure(*map, shapes, x, y);
				if (ft_fillit(map, shapes->next, map_size))
					return (1);
				ft_clean_map(*map, shapes, x, y);
			}
	}
	return (shapes == NULL);
}

static size_t	ft_evaluate_map_size(unsigned points)
{
	size_t map_size;

	map_size = 1;
	while (map_size * map_size < points)
		++map_size;
	return (map_size);
}

char			**ft_do_fillit(t_shape *shapes)
{
	size_t		map_size;
	char		**map;

	map_size = ft_evaluate_map_size(ft_shape_size(shapes) * 4);
	map = ft_map_create(map_size);
	while (!(ft_fillit(&map, shapes, map_size)))
	{
		ft_map_delete(map);
		map = ft_map_create(++map_size);
	}
	return (map);
}
