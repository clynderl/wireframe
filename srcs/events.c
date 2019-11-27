/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:00:19 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/27 15:05:06 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_projection(int key, t_mlx *mlx)
{
	if (key == 35)
	{
		mlx->iso = 0;
	}
	else if (key == 34)
	{
		mlx->iso = 1;
	}
	ft_draw(mlx->map, mlx);
}

void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == 13)
		mlx->cam_zoom++;
	else if (key == 1)
		mlx->cam_zoom = (mlx->size_x + mlx->cam_zoom) > 1 ?
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
		ft_draw(mlx->map, mlx);
	}
}

int		key_press(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == 53)
		exit(0);
	if (key == 34 || key == 35)
		ft_change_projection(key, mlx);
	if (key == 13 || key == 1)
		ft_zoom(key, mlx);
	if (key == 126 || key == 125 || key == 123 || key == 124)
		ft_move_cam(key, mlx);
	if (key == 2)
		ft_default_opt(key, mlx);
	return (0);
}
/*
**int		close(void *param)
**{
**	(void)param;
**	exit(0);
**}
*/
void	ft_hookssetup(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close, mlx);
}
