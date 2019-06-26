/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:47:22 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/16 15:14:11 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelete(t_list **list, t_list **del)
{
	t_list *iter;
	t_list *temp;

	if (!list || !*list || !del || !*del || (temp = NULL))
		return ;
	iter = *list;
	while (iter && iter != *del)
	{
		temp = iter;
		iter = iter->next;
	}
	if (!iter)
		return ;
	if (!temp)
		*list = iter->next;
	else
		temp->next = iter->next;
	ft_lstremove(&iter);
	*del = NULL;
}
