/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:03:35 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/19 15:46:27 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "fillit.h"

void		ft_shape_move(t_shape *shape)
{
	unsigned x;
	unsigned y;

	x = shape->points[0].x;
	y = 0 - 1;
	while (++y < 4)
		shape->points[y].x -= x;
	y = shape->points[0].y;
	if (y > shape->points[1].y)
		y = shape->points[1].y;
	if (y > shape->points[2].y)
		y = shape->points[2].y;
	x = 0 - 1;
	while (++x < 4)
		shape->points[x].y -= y;
}

void		ft_point_struct(char *s, t_shape *shape)
{
	unsigned i;
	unsigned j;

	i = 0 - 1;
	j = 0;
	while (++i < 20)
		if (s[i] == '#')
		{
			shape->points[j].x = i / 5;
			shape->points[j].y = i % 5;
			j++;
		}
}

void		ft_check_symbols(char *s, size_t rd)
{
	unsigned	i;
	unsigned	j;
	size_t		k;

	i = 0 - 1;
	j = 0;
	k = 0;
	while (++i < 20)
	{
		if (!((i + 1) % 5) && s[i] != '\n')
			error();
		else if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
		{
			printf("symbol: %i\n", s[i]);
			error();
		}
		else if (s[i] == '#')
		{
			k += ((i > 4) && (s[i - 5] == '#'));
			k += ((i % 5) && (s[i - 1] == '#'));
			k += ((i < 15) && (s[i + 5] == '#'));
			k += (s[i + 1] == '#');
			j++;
		}
	}
	if (k < 6 || j != 4 || (rd == 21 && s[20] != '\n'))
		error();
}

void		ft_input(int fd, t_shape **shapes)
{
	size_t	rd;
	size_t	check;
	t_shape	shape;
	char	s[21];

	while ((rd = read(fd, s, 21)))
	{
		if (rd != 20 && rd != 21)
			error();
		ft_check_symbols(s, rd);
		ft_point_struct(s, &shape);
		ft_shape_move(&shape);
		ft_shape_append(shapes, ft_shape_new(&shape));
		check = rd;
	}
	if (check == 21)
		error();
	// else if (check != 0)
	// 	return(1);
	// return (0);
}
