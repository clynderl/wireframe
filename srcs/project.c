/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:31:38 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/24 12:04:56 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		x_rotate(int *y, double *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void		y_rotate(int *x, double *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void		z_rotate(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

t_coords	ft_new_point(int x, int y, t_map *map)
{
	t_coords	point;

	point.x = x;
	point.y = y;
	point.z = map->tab[y][x];
	point.color = map->colors[y][x] == 0
				? ft_default_color(point.z, map) : map->colors[y][x];
	return (point);
}

t_coords	ft_project(t_coords point, t_mlx *mlx)
{
	double z_mult;

	point.x *= mlx->size_x + mlx->cam_zoom;
	point.y *= mlx->size_y + mlx->cam_zoom;
	z_mult = mlx->map->z_max > 0 ? 300 / (double)mlx->map->z_max : 3;
	point.z *= z_mult;
	if (mlx->iso)
		ft_iso(&point.x, &point.y, point.z);
	x_rotate(&point.y, &point.z, mlx->alpha);
	y_rotate(&point.x, &point.z, mlx->beta);
	z_rotate(&point.x, &point.y, mlx->gamma);
	point.x += mlx->offset_x + mlx->cam_offset_x;
	point.y += mlx->offset_y + mlx->cam_offset_y;
	return (point);
}
