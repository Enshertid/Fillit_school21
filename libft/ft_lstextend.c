/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstexpend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:49:20 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/18 16:49:21 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstextend(t_list **list, t_list **add)
{
	t_list *iter;

	if (!list || !add || (!*list && !*add))
		return (0);
	if (!*list && *add)
	{
		*list = *add;
		return (1);
	}
	if (*list && !add)
		return (1);
	iter = *list;
	while (iter->next)
		iter = iter->next;
	iter->next = *add;
	return (1);
}
