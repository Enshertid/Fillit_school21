/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:03:12 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/21 12:00:09 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	check_bounds(size_t map_size, size_t x, size_t y,
										const t_shape *shape)
{
	if (x + shape->points[0].x < map_size &&
		y + shape->points[0].y < map_size &&
		x + shape->points[1].x < map_size &&
		y + shape->points[1].y < map_size &&
		x + shape->points[2].x < map_size &&
		y + shape->points[2].y < map_size &&
		x + shape->points[3].x < map_size &&
		y + shape->points[3].y < map_size)
		return (1);
	return (0);
}

static int			ft_check_figure(char **map, t_shape *shapes,
										size_t x, size_t y)
{
	if (map[shapes->points[0].x + x][shapes->points[0].y + y] == '.' &&
		map[shapes->points[1].x + x][shapes->points[1].y + y] == '.' &&
		map[shapes->points[2].x + x][shapes->points[2].y + y] == '.' &&
		map[shapes->points[3].x + x][shapes->points[3].y + y] == '.')
		return (1);
	return (0);
}

static void			ft_place_figure(char **map, t_shape *shapes,
									size_t x, size_t y)
{
	map[shapes->points[0].x + x][shapes->points[0].y + y] = shapes->letter;
	map[shapes->points[1].x + x][shapes->points[1].y + y] = shapes->letter;
	map[shapes->points[3].x + x][shapes->points[3].y + y] = shapes->letter;
	map[shapes->points[2].x + x][shapes->points[2].y + y] = shapes->letter;
	return ;
}

static void			ft_clean_map(char **map, t_shape *shapes,
									size_t x, size_t y)
{
	map[shapes->points[0].x + x][shapes->points[0].y + y] = '.';
	map[shapes->points[1].x + x][shapes->points[1].y + y] = '.';
	map[shapes->points[2].x + x][shapes->points[2].y + y] = '.';
	map[shapes->points[3].x + x][shapes->points[3].y + y] = '.';
	return ;
}

int					ft_fillit(char ***map, t_shape *shapes, size_t map_size)
{
	size_t		x;
	size_t		y;

	x = 0 - 1;
	while (++x < map_size && shapes)
	{
		y = 0 - 1;
		while (++y < map_size && shapes)
		{
			if (check_bounds(map_size, x, y, shapes) &&
				ft_check_figure(*map, shapes, x, y))
			{
				ft_place_figure(*map, shapes, x, y);
				if (ft_fillit(map, shapes->next, map_size))
					return (1);
				ft_clean_map(*map, shapes, x, y);
				if (shapes->next &&
					!ft_memcmp(shapes, shapes->next, sizeof(t_point) * 4))
					return (0);
			}
		}
	}
	if (shapes)
		return (0);
	return (1);
}
