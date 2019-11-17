/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:25:44 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/17 14:17:01 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(t_mlx *mlx, int x, int y)
{
	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
		mlx->str[x + mlx->width * y] = 0xFFFFFF;
}

void	ft_draw_line(t_mlx *mlx, t_coords *c1, t_coords *c2)
{
	t_line	*line;

	if (!(line = (t_line*)malloc(sizeof(t_line))))
		return ;
	if (FT_ABS(c2->x - c1->x) >= FT_ABS(c2->y - c1->y))
		line->delta = FT_ABS(c2->x - c1->x);
	else
		line->delta = FT_ABS(c2->y - c1->y);
	line->dx = (c2->x - c1->x) / line->delta;
	line->dy = (c2->y - c1->y) / line->delta;
	line->x = c1->x + 0.5;
	line->y = c1->y + 0.5;
	line->i = 1;
	while (line->i <= line->delta && line->x < mlx->width
		&& line->y < mlx->height)
	{
		line->mix = line->i / line->delta;
		ft_fill_pixel(mlx, (int)line->x, (int)line->y);
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}
	free(line);
}
