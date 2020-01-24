/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:20:08 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/24 11:48:59 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_projection(int key, t_mlx *mlx)
{
	if (key == 35)
		mlx->iso = 0;
	else if (key == 34)
		mlx->iso = 1;
	ft_draw(mlx->map, mlx);
}

void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == 13)
		mlx->cam_zoom += 1;
	else if (key == 1)
		mlx->cam_zoom = (mlx->size_x - 1 + mlx->cam_zoom - 1) >= 1 ?
		mlx->cam_zoom - 1 : mlx->cam_zoom;
	ft_draw(mlx->map, mlx);
}

void	ft_move_cam(int key, t_mlx *mlx)
{
	if (key == 126)
		mlx->cam_offset_y -= 3;
	else if (key == 125)
		mlx->cam_offset_y += 3;
	else if (key == 123)
		mlx->cam_offset_x -= 3;
	else if (key == 124)
		mlx->cam_offset_x += 3;
	ft_draw(mlx->map, mlx);
}

void	ft_default_opt(int key, t_mlx *mlx)
{
	if (key == 2)
	{
		mlx->cam_offset_x = 0;
		mlx->cam_offset_y = 0;
		mlx->cam_zoom = 0;
		mlx->iso = 1;
		mlx->alpha = 0;
		mlx->beta = 0;
		mlx->gamma = 0;
		ft_draw(mlx->map, mlx);
	}
}

void	ft_rotate(int key, t_mlx *mlx)
{
	if (key == 84)
		mlx->alpha += 0.1;
	else if (key == 87)
		mlx->alpha -= 0.1;
	else if (key == 86)
		mlx->beta -= 0.1;
	else if (key == 88)
		mlx->beta += 0.1;
	else if (key == 83)
		mlx->gamma += 0.1;
	else if (key == 85)
		mlx->gamma -= 0.1;
	ft_draw(mlx->map, mlx);
}
