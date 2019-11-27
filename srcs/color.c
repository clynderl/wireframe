/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:12:57 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/27 14:15:07 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_percent(int start, int end, int curr)
{
	double	place;
	double	dist;

	place = curr - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int		ft_get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int		ft_default_color(int z, t_map *map)
{
	double perc;

	perc = ft_percent(map->z_min, map->z_max, z);
	if (perc < 0.2)
		return (0x8FBC8F);
	else if (perc < 0.5)
		return (0xDAA520);
	else if (perc < 0.8)
		return (0xFFE4C4);
	else
		return (0xFFF5EE);
}

int		ft_get_color(t_coords curr, t_coords end,
		t_coords start, t_coords delta)
{
	int		r;
	int		g;
	int		b;
	double	perc;

	if (delta.x > delta.y)
		perc = ft_percent(start.x, end.x, curr.x);
	else
		perc = ft_percent(start.y, end.y, curr.y);
	r = ft_get_light((start.color >> 16) & 0xFF,
					(end.color >> 16) & 0xFF, perc);
	g = ft_get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, perc);
	b = ft_get_light((start.color) & 0xFF, (end.color) & 0xFF, perc);
	return ((r << 16) | (g << 8) | b);
}
