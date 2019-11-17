/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:31:38 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/17 16:15:08 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_double(t_map *map, t_coords *c1, t_coords *c2, int i, int j, t_mlx *mlx)
{
	c1->x = 50 * i + 200;
	c1->y = 50 * j + 200;
	if (map->cols > j)
	{
		c2->x = c1->x + 50;
		c2->y = c1->y;
		ft_draw_line(mlx, c1, c2);
	}
	if (map->rows > i)
	{
		c2->x = c1->x;
		c2->y = c1->y + 50;
		ft_draw_line(mlx, c1, c2);
	}
}

void	ft_map_img(t_map *map, t_mlx *mlx)
{
	int i;
	int j;
	t_coords *c1;
	t_coords *c2;
	if (!(c1 = (t_coords*)malloc(sizeof(t_coords))))
		return ;
	if (!(c2 = (t_coords*)malloc(sizeof(t_coords))))
		return ;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			draw_double(map, c1, c2, i, j, mlx);
			j++;
		}
		i++;
	}
}
