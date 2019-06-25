#ifndef FILLIT_H
#define FILLIT_H

typedef struct  s_point
{
	unsigned	x;
	unsigned	y;
}				t_point;

typedef t_point Point;

typedef struct  s_shape
{
	Point		points[4];
}				t_shape;

typedef t_shape Shape;

void	error(void);

#endif