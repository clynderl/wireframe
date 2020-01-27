/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:37:51 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/27 12:54:36 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_controls_text(t_mlx *mlx)
{
	int x;
	int y;

	x = 30;
	y = 30;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xC0C0C0, "Controls:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "Change projection:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "I - ISO | P - PARALLEL");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "ARROWS - CAMERA MOVE");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "W,S - BIGGER/SMALLER");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "D - DEFAULT");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "NUMPUD - ROTATION");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "ESC - EXIT");
}
