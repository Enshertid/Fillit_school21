/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_el_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:35:31 by ymanilow          #+#    #+#             */
/*   Updated: 2019/06/25 21:05:08 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		ft_add_el_begin(t_dlist **list, t_dlist *new)
{
	if (new)
	{
		if (!*list)
		{
			*list = new;
			return (1);
		}
		else
		{
			new->next = *list;
			(*list)->prev = new;
		}
		return (1);
	}
	return (0);
}
