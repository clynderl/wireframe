/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:06:17 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/24 11:48:41 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "math.h"

typedef	struct	s_coords
{
	int			x;
	int			y;
	double		z;
	int			color;
}				t_coords;

typedef	struct	s_map
{
	int			**tab;
	int			**colors;
	int			cols;
	int			rows;
	int			z_min;
	int			z_max;
}				t_map;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	void		*img;
	int			*str;
	int			bpp;
	int			sl;
	int			size_x;
	int			size_y;
	int			size_z;
	int			offset_x;
	int			offset_y;
	int			iso;
	int			cam_zoom;
	int			cam_offset_x;
	int			cam_offset_y;
	double		alpha;
	double		beta;
	double		gamma;
	t_map		*map;
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
int				ft_get_color(t_coords start, t_coords end,
				t_coords curr, t_coords delta);
void			ft_map_min_max(t_map *map);
int				ft_default_color(int z, t_map *map);
int				ft_atoi_base(char *str, int base);
void			ft_change_projection(int key, t_mlx *mlx);
void			ft_zoom(int key, t_mlx *mlx);
void			ft_move_cam(int key, t_mlx *mlx);
void			ft_default_opt(int key, t_mlx *mlx);
void			ft_rotate(int key, t_mlx *mlx);
void			ft_iso(int *x, int *y, int z);
#endif
