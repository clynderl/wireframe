/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:31:38 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/24 14:45:43 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_rotatation_x(int *y, double *z, double a)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(a) + *z * sin(a);
	*z = -previous_y * sin(a) + *z * cos(a);
}

void		ft_rotatation_y(int *x, double *z, double b)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(b) + *z * sin(b);
	*z = -previous_x * sin(b) + *z * cos(b);
}

void		ft_rotatation_z(int *x, int *y, double g)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(g) - previous_y * sin(g);
	*y = previous_x * sin(g) + previous_y * cos(g);
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
	point.x *= mlx->cam_zoom;
	point.y *= mlx->cam_zoom;
	point.z *= mlx->cam_zoom / 1;
	point.x -= (mlx->map->rows * mlx->cam_zoom) / 2;
	point.y -= (mlx->map->cols * mlx->cam_zoom) / 2;
	if (mlx->iso)
		ft_iso(&point.x, &point.y, point.z);
	ft_rotatation_x(&point.y, &point.z, mlx->alpha);
	ft_rotatation_y(&point.x, &point.z, mlx->beta);
	ft_rotatation_z(&point.x, &point.y, mlx->gamma);
	//point.x += mlx->offset_x + mlx->cam_offset_x;
	//point.y += mlx->offset_y + mlx->cam_offset_y;
	point.x += (mlx->width - mlx->width / 6)
			/ 2 + mlx->cam_offset_x + mlx->width / 6;
	point.y += (mlx->height + mlx->map->cols * mlx->cam_zoom) / 2
				+ mlx->cam_offset_y;
	return (point);
}
