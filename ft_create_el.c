/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:09:16 by ymanilow          #+#    #+#             */
/*   Updated: 2019/06/25 19:32:21 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_dlist		*ft_create_el(const void* data, size_t size)
{
	t_dlist		*new;

	if (data && size)
	{
		if (!(new = malloc(sizeof(t_dlist))))
			return(NULL);
		if (!(new->data = malloc(size)))
		{
			free(new);
			return(NULL);
		}
		ft_memcpy(new->data, data, size);
		return(new);
	}
	return(NULL);
}
