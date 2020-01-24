/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:00:19 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/24 11:49:19 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (key == 83 || key == 84 || key == 85 || key == 86
	|| key == 87 || key == 88 || key == 89 || key == 90 || key == 92)
		ft_rotate(key, mlx);
	if (key == 2)
		ft_default_opt(key, mlx);
	return (0);
}

int		exit_hook(void *param)
{
	(void)param;
	exit(0);
}

void	ft_hookssetup(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, exit_hook, mlx);
}
