/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_with_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:27:16 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/18 21:36:37 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_map_create(t_lst *list)
{
	size_t			i;
	size_t			j;
	char			**map;

	map = (char**)malloc(sizeof(char*) * (list->map_size + 1));
	i = 0;
	j = 0;
	map[list->map_size] = NULL;
	while (i < list->map_size)
	{
		map[i] = (char*)malloc(sizeof(char) * (list->map_size + 2));
		map[i][list->map_size + 1] = '\0';
		map[i][list->map_size] = '\n';
		i++;
	}
	i = 0;
	while (i < list->map_size)
	{
		while (j < list->map_size)
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

int		ft_check_figure(char	**map, t_shape *shapes, t_lst *list)
{
	if (shapes->points[0].x + list->x >= list->map_size ||
			shapes->points[1].x + list->x >= list->map_size ||
				shapes->points[2].x + list->x >= list->map_size ||
					shapes->points[3].x + list->x >= list->map_size)
		return (0);
	if (map[shapes->points[0].x + list->x][shapes->points[0].y + list->y] == '.' && 
			map[shapes->points[1].x + list->x][shapes->points[1].y + list->y] == '.' &&
				map[shapes->points[2].x + list->x][shapes->points[2].y + list->y] == '.' &&
					map[shapes->points[3].x + list->x][shapes->points[3].y + list->y] == '.')
		return (1);
	else
		return (0);
}

char		**ft_place_figure(char **map, t_shape *shapes, t_lst *list)
{
	map[shapes->points[0].x + list->x][shapes->points[0].y + list->y] = 'A' + list->figure;
	map[shapes->points[1].x + list->x][shapes->points[1].y + list->y] = 'A' + list->figure;
	map[shapes->points[2].x + list->x][shapes->points[2].y + list->y] = 'A' + list->figure;
	map[shapes->points[3].x + list->x][shapes->points[3].y + list->y] = 'A' + list->figure;
	list->figure++;
	return (map);
}

char		**ft_clean_map(char  **map, t_shape *shapes, t_lst *list)
{
	map[shapes->points[0].x + list->x][shapes->points[0].y + list->y] = '.';
	map[shapes->points[1].x + list->x][shapes->points[1].y + list->y] = '.';
	map[shapes->points[2].x + list->x][shapes->points[2].y + list->y] = '.';
	map[shapes->points[3].x + list->x][shapes->points[3].y + list->y] = '.';
	list->figure--;
	return (map);
}