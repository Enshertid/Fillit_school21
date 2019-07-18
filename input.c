/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:36:36 by dbendu            #+#    #+#             */
/*   Updated: 2019/06/25 20:36:39 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "libft.h"

#include "input.h"
#include "shape.h"

static void	shift_shape_in_corner(t_shape *shape)
{
	size_t iter;
	size_t x_shift;
	size_t y_shift;

	x_shift = shape->points[0].x;
	y_shift = ft_min(ft_min(shape->points[0].y,
							shape->points[1].y),
							shape->points[2].y);
	iter = 0 - 1;
	while (++iter < 4)
	{
		shape->points[iter].x -= x_shift;
		shape->points[iter].y -= y_shift;
	}
}

static void	get_shape(t_shape *shape, const char *buf)
{
	size_t	iter;
	size_t	pos;

	iter = 0 - 1;
	pos = 0;
	while (++iter < 20)
		if (buf[iter] == '#')
		{
			shape->points[pos].x = iter / 5;
			shape->points[pos].y = iter % 5;
			++pos;
		}
	shift_shape_in_corner(shape);
}

static void	check_symbols(const char *buf, unsigned bufsize)
{
	int iter;
	int sharps;

	iter = 0 - 1;
	sharps = 0;
	while (++iter < 20)
	{
		if ((iter + 1) % 5)
		{
			if (buf[iter] != '.' && buf[iter] != '#')
				error();
			if (buf[iter] == '#')
				++sharps;
		}
		else if (buf[iter] != '\n')
			error();
	}
	if (sharps != 4 || (bufsize == 21 && buf[20] != '\n'))
		error();
}

static void	check_shapes(const char *buf)
{
	unsigned i;
	unsigned contacts;

	i = 0 - 1;
	contacts = 0;
	while (++i < 19)
	{
		if (buf[i] != '#')
			continue;
		contacts += buf[i + 1] == '#';
		contacts += i > 4 && buf[i - 5] == '#';
		contacts += i % 5 && buf[i - 1] == '#';
		contacts += i < 14 && buf[i + 5] == '#';
	}
	if (contacts < 6)
		error();
}

t_shape		*get_shapes(const int fd)
{
	char		buf[21];
	t_shape		*shapes;
	t_shape		shape;
	unsigned	prev_read;
	unsigned	cur_read;

	prev_read = 0;
	shapes = NULL;
	while ((cur_read = read(fd, buf, 21)))
	{
		check_symbols(buf, cur_read);
		check_shapes(buf);
		get_shape(&shape, buf);
		ft_shapeappend(&shapes, ft_shapenew(&shape));
		prev_read = cur_read;
	}
	if (prev_read == 21)
		error();
	return (shapes);
}
