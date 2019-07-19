/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:00:05 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/19 15:22:40 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "fillit.h"

char		**ft_map_create(size_t map_size)
{
	unsigned	i;
	unsigned	j;
	char		**map;

	map = (char**)malloc(sizeof(char*) * (map_size + 1));
	map[0] = (char*)malloc(map_size * (map_size + 2));
	i = 0;
	while (++i < map_size)
		map[i] = map[i - 1] + map_size + 2;
	i = 0 - 1;
	while (++i < map_size)
	{
		j = 0 - 1;
		while (++j < map_size)
			map[i][j] = '.';
		map[i][j] = '\n';
		map[i][j + 1] = '\0';
	}
	map[map_size] = NULL;
	return (map);
}

void		ft_map_delete(char	**map)
{
	free(map[0]);
	free(map);
}

int		ft_check_figure(char **map, t_shape *shapes ,
						unsigned pos, size_t map_size)
{
	unsigned x;
	unsigned y;

	x = pos / map_size;
	y = pos % map_size;
	if (shapes->points[0].x + x >= map_size ||
			shapes->points[1].x + x >= map_size ||
				shapes->points[2].x + x >= map_size ||
					shapes->points[3].x + x >= map_size)
		return (0);
	return (map[shapes->points[0].x + x][shapes->points[0].y + y] == '.' && 
			map[shapes->points[1].x + x][shapes->points[1].y + y] == '.' &&
			map[shapes->points[2].x + x][shapes->points[2].y + y] == '.' &&
			map[shapes->points[3].x + x][shapes->points[3].y + y] == '.');
}

char		**ft_place_figure(char **map, t_shape *shapes,
								unsigned x, unsigned y)
{
	int letter;

	letter = shapes->letter;
	map[shapes->points[0].x + x][shapes->points[0].y + y] = letter;
	map[shapes->points[1].x + x][shapes->points[1].y + y] = letter;
	map[shapes->points[2].x + x][shapes->points[2].y + y] = letter;
	map[shapes->points[3].x + x][shapes->points[3].y + y] = letter;
	return (map);
}

char		**ft_clean_map(char  **map, t_shape *shapes, size_t x, size_t y)
{
	map[shapes->points[0].x + x][shapes->points[0].y + y] = '.';
	map[shapes->points[1].x + x][shapes->points[1].y + y] = '.';
	map[shapes->points[2].x + x][shapes->points[2].y + y] = '.';
	map[shapes->points[3].x + x][shapes->points[3].y + y] = '.';
	return (map);
}