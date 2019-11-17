/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:41:01 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/17 15:23:28 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_usage(void)
{
	ft_putendl("usage: ./fdf <file>");
	return (0);
}

int		main(int argc, char *argv[])
{
	t_map		*map;
	t_mlx		*mlx;
	t_coords	*c1;
	t_coords	*c2;

	c1 = (t_coords*)malloc(sizeof(t_coords));
	c2 = (t_coords*)malloc(sizeof(t_coords));
	c1->x = 10;
	c1->y = 10;
	c2->x = 10;
	c2->y = 300;
	if (argc != 2)
		ft_usage();
	if (!(map = ft_parse(argv[1])))
		return (0);
	if (!(mlx = ft_mlx_setup(argv[1])))
		return (0);
	ft_mlx_img_setup(mlx);
	ft_map_img(map, mlx);
	ft_draw_line(mlx, c1, c2);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0xFFFFFF, "Hello");
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
