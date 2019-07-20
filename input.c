/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:03:35 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/17 17:04:01 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_point_move(t_shape *shape)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	i = shape->points[0].x;
	while (j < 4)
	{
		shape->points[j].x -= i;
		j++;
	}
	i = 0;
	j = shape->points[0].y;
	if (j > shape->points[1].y)
		j = shape->points[1].y;
	if (j > shape->points[2].y)
		j = shape->points[2].y;
	while (i < 4)
	{
		shape->points[i].y -= j;
		i++;
	}
}

void		ft_point_struct(char *s, t_shape *shape)
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
}

int			ft_check_symbols(char *s, size_t rd)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 20)
	{
		if (!((i + 1) % 5) && s[i] != '\n')
			return (0);
		if (s[i] == '#')
		{
			k += ((i > 4) && (s[i - 5] == '#'));
			k += ((i % 5) && (s[i - 1] == '#'));
			k += ((i < 15) && (s[i + 5] == '#'));
			k += (s[i + 1] == '#');
			j++;
		}
		i++;
	}
	if (k != 6 && k != 8)
		return (0);
	if (j != 4)
		return (0);
	if (rd == 21 && s[20] != '\n')
		return (0);
	return (1);
}

int			ft_input(int fd, t_shape **shapes)
{
	size_t		rd;
	size_t		check;
	t_shape		shape;
	char		s[21];

	while ((rd = read(fd, s, 21)))
	{
		if (rd != 20 && rd != 21)
			return (0);
		check = ft_check_symbols(s, rd);
		if (check == 0)
			return (0);
		ft_point_struct(s, &shape);
		ft_point_move(&shape);
		ft_list_add_to_end(shapes, ft_list_new(shape));
		check = rd;
	}
	if (check == 21)
		return (0);
	else if (check != 0)
		return(1);
	return (0);
}
