/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:06:17 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/25 17:40:41 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include "math.h"

typedef	struct	s_coords
{
	int			x;
	int			y;
	id_t		z;
}				t_coords;

typedef	struct	s_map
{
	int			**tab;
	int			cols;
	int			rows;
}				t_map;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	void		*img;
	int			*str;
	int			size_x;
	int			size_y;
	int			size_z;
	int			offset_x;
	int			offset_y;
}				t_mlx;

t_map			*ft_parse(char *file);
t_mlx			*ft_mlx_setup(char *title);
void			ft_draw_line(t_mlx *mlx, t_coords c1, t_coords c2);
void			ft_mlx_img_setup(t_mlx *mlx);
void			ft_map_img(t_map *map, t_mlx *mlx);
t_coords		ft_project(t_coords point, t_mlx *mlx);
t_coords		ft_new_point(int x, int y, t_map *map);
void			ft_draw(t_map *map, t_mlx *mlx);
void			ft_set_size(t_mlx *mlx, t_map *map);
void			ft_hookssetup(t_mlx *mlx);
void			ft_draw_background(t_mlx *mlx);
void			ft_put_controls_text(t_mlx *mlx);
#endif
