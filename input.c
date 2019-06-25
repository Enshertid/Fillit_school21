#include "fillit.h"
#include "input.h"

static void shift_shape_in_corner(Shape *shape)
{
	size_t iter;
	size_t x_shift;
	size_t y_shift;

	x_shift = ft_min(ft_min(shape->points[0].x, shape->points[1].x),
				ft_min(shape->points[2].x, shape->points[3].x));
	y_shift = ft_min(ft_min(shape->points[0].y, shape->points[1].y),
				ft_min(shape->points[2].y, shape->points[3].y));
	iter = 0 - 1;
	while (++iter < 4)
	{
		shape->points[iter].x -= x_shift;
		shape->points[iter].y -= y_shift;
	}
}

static void get_shape(Shape *shape, const char *buf)
{
	size_t	iter;
	size_t  pos;

	iter = 0;
	pos = 0;
	while (iter < 20)
	{
		if (buf[iter] == '#')
		{
			shape->points[pos].x = iter / 5;
			shape->points[pos].y = iter % 5;
			++pos;
		}
		++iter;
	}
	shift_shape_in_corner(shape);
}

static void check_symbols(const char *buf, int size)
{
	int iter;
	int sharps;

	iter = 0;
	sharps = 0;
	while (iter < 20)
	{
		if ((iter + 1) % 5)
		{
			if (buf[iter] != '.' && buf[iter] != '#')
				error();
			if (buf[iter] == '#' && ++sharps > 4)
				error();
		}
		else if (buf[iter] != '\n')
			error();
		++iter;
	}
	if (sharps != 4 || (size == 21 && buf[20] != '\n'))
		error();
}

static void check_shapes(const char *buf)
{
	size_t i;

	i = 0;
	while (i < 14)
	{
		if (buf[i] == '#')
		{
			if (buf[i + 4] == '#' && buf[i - 1] != '#' && buf[i + 5] != '#')
				error();
			if (buf[i + 6] == '#' && buf[i + 1] != '#' && buf[i + 5] != '#')
				error();
		}
		++i;
	}
}

t_list *processing_input(const int fd)
{
	char	buf[21];
	t_list	*shapes;
	size_t	prev_read;
	size_t	cur_read;
	Shape	shape;

	prev_read = 0;
	shapes = NULL;
	while ((cur_read = read(fd, buf, 21)))
	{
		check_symbols(buf, cur_read);
		check_shapes(buf);
		get_shape(&shape, buf);
		ft_lstappend(&shapes, ft_lstnew(&shape, sizeof(Shape)));
		prev_read = cur_read;
	}
	if (prev_read == 21)
		error();
	return (shapes);
}
