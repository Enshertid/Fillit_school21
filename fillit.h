/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:28:29 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/18 21:59:13 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include "libft/libft.h"
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
}					t_shape;

typedef struct		s_lst
{
	size_t			map_size;
	size_t			figure;
	size_t			x;
	size_t			y;	
}					t_lst;

void				ft_list_add_to_end(t_shape **list, t_shape *new);
t_shape				*ft_list_new(t_shape shapes);
int					ft_input(int fd, t_shape **shapes);
char				**ft_map_create(t_lst	*list);
void				ft_map_delete(char	**map);
int					ft_check_figure(char	**map, t_shape *shapes,
					t_lst *list);
char				**ft_place_figure(char **map, t_shape *shapes, t_lst *list);
char				**ft_clean_map(char  **map, t_shape *shapes, t_lst *list);

#endif
