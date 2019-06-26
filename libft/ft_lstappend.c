/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:49:20 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/18 16:49:21 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstappend(t_list **list, t_list *elem)
{
	register t_list *iter;

	if (list && elem)
	{
		iter = *list;
		if (iter)
		{
			while (iter->next)
				iter = iter->next;
			iter->next = elem;
		}
		else
			*list = elem;
		return (1);
	}
	return (0);
}
