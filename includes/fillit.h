/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:28:29 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/19 16:34:24 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "fcntl.h"

# include "libft.h"

typedef struct		s_point
{
	unsigned int	x;
	unsigned int	y;
}					t_point;

typedef struct		s_shape
{
	t_point			points[4];
	struct s_shape	*next;
	struct s_shape	*end;
	int				letter;
}					t_shape;

char				**ft_do_fillit(t_shape *shapes);
void				ft_input(int fd, t_shape **shapes);
void				error(void);
void				ft_shapes_clear(t_shape **list);
void				ft_map_delete(char	**map);
int					ft_check_figure(char **map, t_shape *shapes,
								unsigned pos, size_t map_size);
char				**ft_place_figure(char **map, t_shape *shapes,
								unsigned x, unsigned y);
char				**ft_clean_map(char **map, t_shape *shapes,
								unsigned x, unsigned y);
size_t				ft_shape_size(const t_shape *list);
char				**ft_map_create(size_t map_size);
void				ft_shape_move(t_shape *shape);
void				ft_shape_append(t_shape **list, t_shape *new);
t_shape				*ft_shape_new(const t_shape *shape);

#endif
