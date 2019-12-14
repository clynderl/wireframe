/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:31:38 by clynderl          #+#    #+#             */
/*   Updated: 2019/12/11 16:49:35 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

void		x_rotation(int *y, int *z, double ang)
{
	int prev_y;
	int prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = (prev_y * cos(ang)) + (prev_z * sin(ang));
	*z = (-prev_y * sin(ang)) + (prev_z * cos(ang));
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
	point.x *= mlx->size_x + mlx->cam_zoom;
	point.y *= mlx->size_y + mlx->cam_zoom;
	point.z *= 5;
	if (mlx->iso)
		iso(&point.x, &point.y, point.z);
	//x_rotation(&point.x, &point.y, 0.7);
	point.x += mlx->offset_x + mlx->cam_offset_x;
	point.y += mlx->offset_y + mlx->cam_offset_y;
	return (point);
}
