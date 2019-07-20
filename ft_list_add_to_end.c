/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_to_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:17:37 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/14 20:37:35 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_list_add_to_end(t_shape **list, t_shape *new)
{
	t_shape *it;

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
