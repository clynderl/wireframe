/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:37:51 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/27 15:01:28 by clynderl         ###   ########.fr       */
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
				y += 30, 0xC0C0C0, "I - ISO | P - Parallel");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "Arrows - Camera move");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "W,S - Zoom");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "D - Default");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x,
				y += 30, 0xC0C0C0, "Esc - Exit");
}
