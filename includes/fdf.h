/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:06:17 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/17 14:53:45 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef	struct	s_line
{
	int			delta;
	double		dx;
	double		dy;
	double		x;
	double		y;
	int			i;
	double		mix;
}				t_line;

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
}				t_mlx;

t_map			*ft_parse(char *file);
t_mlx			*ft_mlx_setup(char *title);
void			ft_draw_line(t_mlx *mlx, t_coords *c1, t_coords *c2);
void			ft_mlx_img_setup(t_mlx *mlx);
void			ft_map_img(t_map *map, t_mlx *mlx);
#endif
