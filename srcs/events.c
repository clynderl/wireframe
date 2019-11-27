/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:00:19 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/27 13:46:25 by clynderl         ###   ########.fr       */
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

int		key_press(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == 53)
		exit(0);
	if (key == 34 || key == 35)
		ft_change_projection(key, mlx);
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
