/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:11:25 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/14 15:11:28 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "solve.h"
#include "shape.h"

void fill_map(char ***map, size_t mapsize)
{
	unsigned row;
	unsigned col;

	row = 0;
	while (row < mapsize)
	{
		col = 0;
		while (col < mapsize)
			(*map)[row][col++] = '.';
		(*map)[row][mapsize] = '\n';
		(*map)[row][mapsize + 1] = '\0';
		++row;
	}
}

void increase_map(char ***map, size_t mapsize)
{
	unsigned iter;

	if (*map)
	{
		free((*map)[0]);
		free(*map);
	}
	if (!(*map = (char**)malloc(sizeof(char*) * (mapsize + 1))))
		error();
	if (!((*map)[0] = (char*)malloc(mapsize * (mapsize + 2))))
		error();
	iter = 0;
	while (++iter < mapsize)
		(*map)[iter] = (*map)[iter - 1] + mapsize + 2;
	(*map)[mapsize] = NULL;
	fill_map(map, mapsize);
}

size_t prepare_map(char ***map, const t_shape *shapes)
{
	unsigned min_points;
	size_t mapsize;

	min_points = ft_shapesize(shapes) * 4;
	mapsize = 1;
	while (mapsize * mapsize < min_points)
		++mapsize;
	increase_map(map, mapsize);
	return (mapsize);
}

void remove_shape(char **map, unsigned row, unsigned col, t_shape *shape)
{
	unsigned i;

	i = 0 - 1;
	while (++i < 4)
			map[row + shape->points[i].x][col + shape->points[i].y] = '.';
		shape->is_place = 0;
}

int place_shape(char **map, size_t mapsize, unsigned row, unsigned col,
					t_shape *shape)
{
	unsigned	i;
	int			letter;

	i = 0 - 1;
	while (++i < 4)
		if (row + shape->points[i].x >= mapsize ||
			col + shape->points[i].y >= mapsize ||
			map[row + shape->points[i].x][col + shape->points[i].y] != '.')
			return (0);
	i = 0 - 1;
	letter = shape->letter;
	while (++i < 4)
		map[row + shape->points[i].x][col + shape->points[i].y] = letter;
	shape->is_place = 1;
	return (1);
}

t_shape *find_not_set_shape(const t_shape *shapes)
{
	if (!shapes)
		return (NULL);
	while (shapes && shapes->is_place)
		shapes = shapes->next;
	return ((t_shape*)shapes);
}

// int fillit(char **map, size_t mapsize, t_shape *shapes)
// {
// 	t_shape *cur_shape;
// 	unsigned row;
// 	unsigned col;
// 	int flag;

// 	cur_shape = shapes;
// 	while ((cur_shape = find_not_set_shape(cur_shape)))
// 	{
// 		flag = 1;
// 		row = 0 - 1;
// 		while (flag && ++row < mapsize)
// 		{
// 			col = 0 - 1;
// 			while (flag && ++col < mapsize)
// 				if (place_shape(map, mapsize, row, col, cur_shape))
// 				{
// 					if (fillit(map, mapsize, shapes))
// 						return (1);
// 					remove_shape(map, row, col, cur_shape);
// 					flag = 0;
// 				}
// 		}
// 		cur_shape = cur_shape->next;
// 	}
// 	return (!find_not_set_shape(shapes));
// }

int fillit(char **map, size_t mapsize, t_shape *shapes)
{
	t_shape *cur_shape;
	unsigned row;
	unsigned col;

	cur_shape = shapes;
	while ((cur_shape = find_not_set_shape(cur_shape)))
	{
		row = 0 - 1;
		while (++row < mapsize)
		{
			col = 0 - 1;
			while (++col < mapsize)
				if (place_shape(map, mapsize, row, col, cur_shape))
				{
					if (fillit(map, mapsize, shapes))
						return (1);
					remove_shape(map, row, col, cur_shape);
				}
		}
		cur_shape = cur_shape->next;
	}
	return (!find_not_set_shape(shapes));
}

char **solve(t_shape *shapes)
{
	char **map;
	size_t mapsize;

	if (!shapes)
		return (NULL);
	map = NULL;
	mapsize = prepare_map(&map, shapes);
	while (!fillit(map, mapsize, shapes))
	{
		increase_map(&map, ++mapsize);
		fillit(map, mapsize, shapes);
	}
	return (map);
}
