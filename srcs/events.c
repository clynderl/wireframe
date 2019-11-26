/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:00:19 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/26 16:19:41 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == 53)
		exit(0);
	return (0);
	if (key == 48)
	{
		mlx->iso = 0;
	}
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
	mlx_hook(mlx->win_ptr, 48, 0, key_press, mlx);
}
