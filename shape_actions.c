/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:27:59 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/20 18:35:08 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_shape		*ft_list_new(t_shape *shapes)
{
	t_shape *new;

	if (!(new = malloc(sizeof(t_shape))))
		return (NULL);
	ft_memcpy(new->points, shapes->points, sizeof(t_point) * 4);
	new->next = NULL;
	return (new);
}

int			ft_list_add_to_end(t_shape **list, t_shape *new)
{
	t_shape *it;

	if (list && *list && new)
	{
		it = *list;
		while (it->next)
			it = it->next;
		it->next = new;
		new->letter = it->letter + 1;
		new->next = NULL;
	}
	else if (new)
	{
		*list = new;
		new->letter = 'A';
	}
	return (1);
}

void		ft_shapes_clear(t_shape *shapes)
{
	t_shape *temp;

	while (shapes)
	{
		temp = shapes->next;
		free(shapes);
		shapes = temp;
	}
}
