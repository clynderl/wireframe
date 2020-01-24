/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:25:44 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/27 15:22:42 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_background(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			if (j < mlx->width / 6)
				mlx->str[i * mlx->width + j] = 0x161616;
			else
				mlx->str[i * mlx->width + j] = 0x242424;
			j++;
		}
		i++;
	}
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int i;

	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
	{
		i = x + mlx->width * y;
		mlx->str[i] = color;
	}
}

void	ft_draw_line(t_mlx *mlx, t_coords c1, t_coords c2)
{
	t_coords	d;
	t_coords	s;
	t_coords	c;
	int			err[2];

	d.x = FT_ABS(c1.x - c2.x);
	d.y = FT_ABS(c1.y - c2.y);
	s.x = c2.x < c1.x ? 1 : -1;
	s.y = c2.y < c1.y ? 1 : -1;
	err[0] = d.x - d.y;
	c = c2;
	while (c.x != c1.x || c.y != c1.y)
	{
		ft_put_pixel(mlx, c.x, c.y, ft_get_color(c, c2, c1, d));
		if ((err[1] = err[0] * 2) > -d.y)
		{
			err[0] -= d.y;
			c.x += s.x;
		}
		if (err[1] < d.x)
		{
			err[0] += d.x;
			c.y += s.y;
		}
	}
}

void	ft_draw(t_map *map, t_mlx *mlx)
{
	int	x;
	int	y;

	ft_draw_background(mlx);
	y = -1;
	while (++y < map->cols)
	{
		x = -1;
		while (++x < map->rows)
		{
			if (x != map->rows - 1)
			{
				ft_draw_line(mlx, ft_project(ft_new_point(x, y, map), mlx),
				ft_project(ft_new_point(x + 1, y, map), mlx));
			}
			if (y != map->cols - 1)
			{
				ft_draw_line(mlx, ft_project(ft_new_point(x, y, map), mlx),
				ft_project(ft_new_point(x, y + 1, map), mlx));
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	ft_put_controls_text(mlx);
}
