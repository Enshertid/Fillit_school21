/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:17:41 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/14 20:37:57 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_shape		*ft_list_new(t_shape shapes)
{
	t_shape		*new;

	if (!(new = malloc(sizeof(t_shape))))
		return (NULL);
	ft_memcpy(new->points, shapes.points, sizeof(t_point) * 4);
	new->next = NULL;
	return (new);
}
