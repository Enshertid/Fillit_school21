/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:28:29 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/20 09:53:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_point
{
	unsigned int	x;
	unsigned int	y;
}					t_point;

typedef struct		s_shapes
{
	t_point				points[4];
	struct s_shapes		*next;
	int letter;
}					t_shape;

void				ft_list_add_to_end(t_shape **list, t_shape *new);
t_shape				*ft_list_new(t_shape shapes);
int					ft_input(int fd, t_shape **shapes);
void error(void);

#endif
