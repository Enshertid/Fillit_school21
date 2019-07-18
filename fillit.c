/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:03:12 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/18 21:51:59 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 		ft_fillit(char ***map, t_shape *shapes, t_lst *list)
{
	list->x = 0;
	list->y = 0;
	while ((*map)[list->x] && shapes)
	{
		while ((*map)[list->x][list->y] && shapes)
		{
			if (ft_check_figure(*map, shapes, list))
			{
				ft_place_figure(*map, shapes, list);
				if (ft_fillit(map, shapes->next, list))
					return (1);
				else
					ft_clean_map(*map, shapes, list);
			}
			list->y ++;
		}
		list->y = 0;
		list->x++;
	}
	if (shapes)
		return (0);
	return(1);
}

int			ft_do_fillit(char **map, t_shape *shapes, t_lst *list)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (!(ft_fillit(&map, shapes, list)))
	{
		ft_map_delete(map);
		++list->map_size;
		map = ft_map_create(list);
	}
	j= 0;
	while(map[j])
		printf("%s",map[j++]);
	return (1);
}

void		ft_map_size_explain(t_lst *list)
{
	size_t			map_size;
	
	map_size = 1;
	list->figure *= 4;
	while (map_size * map_size < list->figure)
		map_size++;
	list->map_size = map_size;
}

void		ft_error()
{
	write(1, "error\n", 6);
	exit(0);
}

int			main()
{
	size_t				fd;
	char				**map;
	t_shape				*shapes;
	t_shape				*new;
	t_lst				*list;

	if (!(list = malloc(sizeof(t_lst))))
		return (0);
	// if (ac != 2)
	// {
	// 	write (1, "Use 1 argument\n", 15);
	// 	exit(0);
	// }
	if (!(fd = open("/Users/ymanilow/Curcus42/fillit_first/file.txt", O_RDONLY)))
		ft_error();
	if (!(ft_input(fd, &shapes)))
		ft_error();
	new = shapes;
	list->figure = 0;
	while(new)
	{
		new = new->next;
		list->figure++;
	}
	ft_map_size_explain(list);
	map = ft_map_create(list);
	list->figure = 0;
	ft_do_fillit(map, shapes, list);
	return (0);
}
