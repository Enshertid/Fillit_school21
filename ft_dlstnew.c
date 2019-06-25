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
#include "libft.h"

t_dlist		*ft_dlstnew(const void *data, size_t size)
{
	t_dlist *new;

	if (!data || !size)
		return (NULL);
	if (!(new = malloc(sizeof(t_dlist))))
		return (NULL);
	if (!(new->data = malloc(size)))
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->data, data, size);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
