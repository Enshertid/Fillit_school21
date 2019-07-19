/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:55:36 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/19 15:41:39 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "fillit.h"

t_shape		*ft_shape_new(const t_shape *shape)
{
	t_shape *new;

	if (!(new = malloc(sizeof(t_shape))))
		return (NULL);
	ft_memcpy(new->points, shape->points, sizeof(t_point) * 4);
	new->next = NULL;
	return (new);
}

void	ft_shapes_clear(t_shape **list)
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

void	ft_shape_append(t_shape **list, t_shape *new)
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

size_t	ft_shape_size(const t_shape *list)
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
