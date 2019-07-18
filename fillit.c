/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:03:12 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/18 12:55:15 by ymanilow         ###   ########.fr       */
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

char		**ft_place_figure(char **map, t_shape *shapes, size_t x, size_t y, size_t f)
{
	map[shapes->points[0].x + x][shapes->points[0].y + y] = 'A' + f;
	map[shapes->points[1].x + x][shapes->points[1].y + y] = 'A' + f;
	map[shapes->points[2].x + x][shapes->points[2].y + y] = 'A' + f;
	map[shapes->points[3].x + x][shapes->points[3].y + y] = 'A' + f;
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

int 		ft_fillit(char		***map, t_shape *shapes, size_t map_size, size_t f)
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
				ft_place_figure(*map, shapes, x, y, f);
				f++;
				if (ft_fillit(map, shapes->next, map_size, f))
					return (1);
				else
				{
					ft_clean_map(*map, shapes, x, y);
					f--;
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

int			ft_do_fillit(char **map, t_shape *shapes, size_t map_size)
{
	size_t		i;

	i = 0;
	while (!(ft_fillit(&map, shapes, map_size, i)))
	{
		ft_map_delete(map);
		map = ft_map_create(++map_size);
	}
	size_t j = 0;
	while(map[j])
		printf("%s",map[j++]);
	return (1);
}

int			main(int ac, char **av)
{
	size_t				fd;
	size_t				k;
	char				**map;
	t_shape				*shapes;
	t_shape				*new;

	k = ac;
	fd = open(av[1], O_RDONLY);
	if (ft_input(fd, &shapes) == 0)
	{
		printf("error");
		return (0);
	}
	new = shapes;
	k = 0;
	while(new)
	{
		new = new->next;
		k++;
	}
	if (k <= 2)
		k = 2;
	else if (k <= 3)
		k = 3;
	else if (k <= 4)
		k = 4;
	else if (k <= 6)
		k = 5;
	else if (k <= 9)
		k = 6;
	else if (k <= 12)
		k = 7;
	else if (k <= 16)
		k = 8;
	map = ft_map_create(k);
	ft_do_fillit(map, shapes, k);
	return (0);
}
//DO USAGE!!!!!!!!!!!!!!!!!

// int			main()
// {
// 	size_t				fd;
// 	size_t				k;
// 	char				**map;
// 	t_shape				*shapes;
// 	t_shape				*new;

// 	fd = open("/Users/ymanilow/Curcus42/fillit/valid_7", O_RDONLY);
// 	if (ft_input(fd, &shapes) == 0)
// 	{
// 		printf("error");
// 		return (0);
// 	}
// 	new = shapes;
// 	k = 0;
// 	while(new)
// 	{
// 		new = new->next;
// 		k++;
// 	}
// 	if (k <= 4)
// 		k = 4;
// 	else if (k <= 6)
// 		k = 5;
// 	else if (k <= 9)
// 		k = 6;
// 	else if (k <= 12)
// 		k = 7;
// 	else if (k <= 16)
// 		k = 8;
// 	map = ft_map_create(k);
// 	ft_do_fillit(map, shapes, k);
// 	return (0);
// }
