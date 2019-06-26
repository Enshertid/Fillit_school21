/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:38:32 by dbendu            #+#    #+#             */
/*   Updated: 2019/06/25 20:38:33 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_point
{
	unsigned	x;
	unsigned	y;
}				t_point;

typedef struct	s_shape
{
	t_point		points[4];
}				t_shape;

void			error(void);

#endif
