/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:28:29 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/20 18:35:14 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_point
{
	unsigned int		x;
	unsigned int		y;
}						t_point;

typedef struct			s_shapes
{
	t_point				points[4];
	struct s_shapes		*next;
	struct s_shapes		*end;
	size_t				letter;
}						t_shape;

void					ft_map_delete(char	**map);
size_t					ft_input(int fd, t_shape **shapes);
char					**ft_map_create(size_t k);
int						ft_fillit(char ***map, t_shape *shapes,
											size_t map_size);
t_shape					*ft_list_new(t_shape *shapes);
int						ft_list_add_to_end(t_shape **list, t_shape *new);
void					ft_shapes_clear(t_shape *shapes);

#endif
