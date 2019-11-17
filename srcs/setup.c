/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:29:58 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/17 14:07:35 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_img_setup(t_mlx *mlx)
{
	int		bpp;
	int		sl;
	int		endian;

	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->str = (int *)mlx_get_data_addr(mlx->img, &bpp, &sl, &endian);
}

t_mlx	*ft_mlx_setup(char *title)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->height = 1080;
	mlx->width = 1920;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, title);
	return (mlx);
}
