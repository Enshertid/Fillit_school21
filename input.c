/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:03:35 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/20 18:35:22 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_point_move(t_shape *shape)
{
	size_t	i;
	size_t	j;

	j = 0 - 1;
	i = shape->points[0].x;
	while (++j < 4)
		shape->points[j].x -= i;
	j = shape->points[0].y;
	if (j > shape->points[1].y)
		j = shape->points[1].y;
	if (j > shape->points[2].y)
		j = shape->points[2].y;
	i = 0 - 1;
	while (++i < 4)
		shape->points[i].y -= j;
	return ;
}

int				ft_point_struct(char *s, t_shape *shape)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			shape->points[j].x = i / 5;
			shape->points[j].y = i % 5;
			j++;
		}
		i++;
	}
	return (1);
}

int				ft_check_symbols(char *s, size_t rd)
{
	size_t	i;
	size_t	j;
	size_t	sharps;

	i = 0 - 1;
	j = 0;
	sharps = 0;
	while (++i < 20)
	{
		if (!((i + 1) % 5) && s[i] != '\n')
			return (0);
		if (s[i] == '#')
		{
			sharps += ((i > 4) && (s[i - 5] == '#'));
			sharps += ((i % 5) && (s[i - 1] == '#'));
			sharps += ((i < 15) && (s[i + 5] == '#'));
			sharps += (s[i + 1] == '#');
			j++;
		}
	}
	if (sharps < 6 || j != 4 || (rd == 21 && s[20] != '\n'))
		return (0);
	return (1);
}

size_t			ft_input(int fd, t_shape **shapes)
{
	size_t		rd;
	size_t		check;
	t_shape		shape;
	size_t		count;
	char		s[21];

	count = 0;
	while ((rd = read(fd, s, 21)))
	{
		++count;
		if (rd != 20 && rd != 21)
			return (0);
		check = ft_check_symbols(s, rd);
		if (!check)
			return (0);
		ft_point_struct(s, &shape);
		ft_point_move(&shape);
		ft_list_add_to_end(shapes, ft_list_new(&shape));
		check = rd;
	}
	if (check != 20)
		return (0);
	return (count);
}
