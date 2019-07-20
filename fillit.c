/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:03:12 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/20 09:55:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_map_create(size_t k)
{
	size_t			i;
	size_t			j;
	char			**map;

	map = (char**)malloc(sizeof(char*) * (k + 1));
	i = 0;
	j = 0;
	map[k] = NULL;
	while (i < k)
	{
		map[i] = (char*)malloc(sizeof(char) * (k + 2));
		map[i][k + 1] = '\0';
		map[i][k] = '\n';
		i++;
	}
	i = 0;
	j = 0;
	while (i < k)
	{
		while (j < k)
		{
			map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

void		ft_map_delete(char	**map)
{
	size_t	i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	i = 0;
	free(map);
}

int		ft_check_figure(char	**map, t_shape *shapes , size_t x, size_t y, size_t map_size)
{
	if (shapes->points[0].x + x >= map_size ||
			shapes->points[1].x + x >= map_size ||
				shapes->points[2].x + x >= map_size ||
					shapes->points[3].x + x >= map_size)
		return (0);
	if (map[shapes->points[0].x + x][shapes->points[0].y + y] == '.' && 
			map[shapes->points[1].x + x][shapes->points[1].y + y] == '.' &&
				map[shapes->points[2].x + x][shapes->points[2].y + y] == '.' &&
					map[shapes->points[3].x + x][shapes->points[3].y + y] == '.')
		return (1);
	else
		return (0);
}

char		**ft_place_figure(char **map, t_shape *shapes, size_t x, size_t y)
{
	map[shapes->points[0].x + x][shapes->points[0].y + y] = shapes->letter;
	map[shapes->points[1].x + x][shapes->points[1].y + y] = shapes->letter;
	map[shapes->points[2].x + x][shapes->points[2].y + y] = shapes->letter;
	map[shapes->points[3].x + x][shapes->points[3].y + y] = shapes->letter;
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

int 		ft_fillit(char		***map, t_shape *shapes, size_t map_size)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while ((*map)[x] && shapes)
	{
		while ((*map)[x][y] && shapes)
		{
			if (ft_check_figure(*map, shapes, x, y, map_size))
			{
				ft_place_figure(*map, shapes, x, y);
				if (ft_fillit(map, shapes->next, map_size))
					return (1);
				else
				{
					ft_clean_map(*map, shapes, x, y);
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (shapes)
		return (0);
	return(1);
}

size_t	ft_shape_size(const t_shape *list)
{
	size_t size;

	size = 0;
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}


char**			ft_do_fillit(t_shape *shapes)
{
	size_t map_size;
	size_t points;
	char **map;

	map_size = 1;
	points = ft_shape_size(shapes);
	while (map_size * map_size < points)
		++map_size;
	map = ft_map_create(map_size);
	while (!(ft_fillit(&map, shapes, map_size)))
	{
		ft_map_delete(map);
		map = ft_map_create(++map_size);
	}
	size_t j = 0;
	while(map[j])
		printf("%s",map[j++]);
	return (map);
}
