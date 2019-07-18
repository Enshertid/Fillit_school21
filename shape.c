/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:42:13 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/14 14:42:14 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shape.h"

t_shape	*ft_shapenew(const t_shape *src)
{
	t_shape *shape;

	if (!src ||
		!(shape = (t_shape*)malloc(sizeof(t_shape))))
		return (NULL);
	ft_memcpy(shape->points, src->points, sizeof(src->points));
	shape->next = NULL;
	shape->end = NULL;
	shape->is_place = 0;
	return (shape);
}

void	ft_shapeappend(t_shape **list, t_shape *new)
{
	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		new->end = new;
		new->letter = 'A';
	}
	else
	{
		new->letter = (*list)->end->letter + 1;
		(*list)->end->next = new;
		(*list)->end = new;
	}
}

void	ft_shapeclear(t_shape **list)
{
	register t_shape *iter;
	register t_shape *temp;

	if (!list || !*list)
		return ;
	iter = *list;
	while (iter)
	{
		temp = iter->next;
		free(iter);
		iter = temp;
	}
	*list = NULL;
}

size_t	ft_shapesize(const t_shape *list)
{
	size_t size;

	size = 0;
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}
