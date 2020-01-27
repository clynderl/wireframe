/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:31:38 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/27 16:53:07 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	point.z *= mlx->cam_zoom;
	point.x -= (mlx->map->rows * mlx->cam_zoom) / 2;
	point.y -= (mlx->map->cols * mlx->cam_zoom) / 2;
	if (mlx->iso)
		ft_iso(&point.x, &point.y, point.z);
	ft_rotatation_x(&point.y, &point.z, mlx->alpha);
	ft_rotatation_y(&point.x, &point.z, mlx->beta);
	ft_rotatation_z(&point.x, &point.y, mlx->gamma);
	point.x += (mlx->width - mlx->width / 6)
			/ 2 + mlx->cam_offset_x + mlx->width / 6;
	point.y += (mlx->height + mlx->map->rows * mlx->cam_zoom) / 2
				+ mlx->cam_offset_y;
	return (point);
}
