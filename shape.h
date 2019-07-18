/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:40:56 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/14 14:40:58 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "stdlib.h"

typedef struct		s_point
{
	unsigned		x;
	unsigned		y;
}					t_point;

typedef struct		s_shape
{
	t_point			points[4];
	struct s_shape	*next;
	struct s_shape	*end;
	int				is_place;
	int				letter;
}					t_shape;

void				ft_shapeclear(t_shape **list);
t_shape				*ft_shapenew(const t_shape *src);
size_t				ft_shapesize(const t_shape *list);
void				ft_shapeappend(t_shape **list, t_shape *new);

#endif
