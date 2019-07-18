/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:40:36 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/14 19:21:57 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_add_end(t_list **list, t_list *new)
{
	t_list *it;

	if (list && *list && new)
	{
		it = *list;
		while (it->next)
			it = it->next;
		it->next = new;
		new->next = NULL;
	}
	else if (new)
		*list = new;
}
