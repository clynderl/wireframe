/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:29:58 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/27 16:48:02 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_img_setup(t_mlx *mlx)
{
	int		endian;

	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->str = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &endian);
}

void	ft_set_size(t_mlx *mlx, t_map *map)
{
	int size_x;
	int size_y;
	int size;

	size_x = mlx->width / 2 / map->rows;
	size_y = mlx->height / 2 / map->cols;
	size = size_x <= size_y ? size_x : size_y;
	mlx->size_x = size;
	mlx->size_y = size;
	mlx->offset_x = (mlx->width / 2);
	mlx->offset_y = mlx->height - mlx->height / 1.3;
}

t_mlx	*ft_mlx_setup(char *title, t_map *map)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->height = 1080;
	mlx->width = 1920;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, title);
	mlx->iso = 1;
	mlx->cam_zoom = FT_MIN((mlx->width - mlx->width / 6) / map->cols / 2,
					mlx->height / map->rows / 2);
	mlx->cam_offset_x = 0;
	mlx->cam_offset_y = 0;
	return (mlx);
}
