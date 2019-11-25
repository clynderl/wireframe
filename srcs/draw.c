/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:25:44 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/25 17:31:49 by clynderl         ###   ########.fr       */
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
			if (j < mlx->width / 5)
				mlx->str[i * mlx->width + j] = 0x161616;
			else
				mlx->str[i * mlx->width + j] = 0x242424;
			j++;
		}
		i++;
	}
}

void	ft_put_pixel(t_mlx *mlx, int x, int y)
{
	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
		mlx->str[x + mlx->width * y] = 0xFFFFFF;
}

void	ft_draw_line(t_mlx *mlx, t_coords c1, t_coords c2)
{
	t_coords	d;
	t_coords	s;
	t_coords	c;
	int			err[2];

	d.x = FT_ABS(c2.x - c1.x);
	d.y = -FT_ABS(c2.y - c1.y);
	s.x = c1.x < c2.x ? 1 : -1;
	s.y = c1.y < c2.y ? 1 : -1;
	err[0] = d.x + d.y;
	c = c1;
	while (c.x != c2.x && c.y != c2.y)
	{
		ft_put_pixel(mlx, c.x, c.y);
		if ((err[1] = 2 * err[0]) >= d.y)
		{
			err[0] += d.y;
			c.x += s.x;
		}
		if (err[1] <= d.x)
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

	y = 0;
	while (y < map->cols)
	{
		x = 0;
		while (x < map->rows)
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
			x++;
		}
		y++;
	}
}
