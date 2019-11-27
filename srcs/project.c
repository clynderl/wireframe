/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:31:38 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/27 13:06:56 by clynderl         ###   ########.fr       */
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

t_coords	ft_new_point(int x, int y, t_map *map)
{
	t_coords	point;

	point.x = x;
	point.y = y;
	point.z = map->tab[y][x];
	point.color = ft_default_color(point.z, map);
	return (point);
}

t_coords	ft_project(t_coords point, t_mlx *mlx)
{
	point.x *= mlx->size_x;
	point.y *= mlx->size_y;
	point.z *= 5;
	if (mlx->iso)
		iso(&point.x, &point.y, point.z);
	point.x += mlx->offset_x;
	point.y += mlx->offset_y;
	return (point);
}
