/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:37:51 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/25 17:41:57 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_controls_text(t_mlx *mlx)
{
	int x;
	int y;

	x = 30;
	y = 30;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xFFFFFF, "Controls:");
}
