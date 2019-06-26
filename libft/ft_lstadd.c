/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:14:43 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/08 20:14:44 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd(t_list **list, t_list *new_elem)
{
	if (list && new_elem)
	{
		new_elem->next = *list;
		*list = new_elem;
		return (1);
	}
	return (0);
}