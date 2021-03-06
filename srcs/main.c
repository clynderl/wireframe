/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:41:01 by clynderl          #+#    #+#             */
/*   Updated: 2020/02/02 19:22:58 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_usage(void)
{
	ft_putendl("usage: ./fdf <file>");
	return (0);
}

int		main(int argc, char *argv[])
{
	t_map		*map;
	t_mlx		*mlx;

	if (argc != 2)
		return (ft_usage());
	if (!(map = ft_parse(argv[1])))
	{
		ft_putendl("File is not valid");
		return (0);
	}
	if (!(mlx = ft_mlx_setup(argv[1], map)))
		return (0);
	if (!(ft_map_min_max(map)))
	{
		ft_putendl("Error");
		return (0);
	}
	ft_set_size(mlx);
	ft_mlx_img_setup(mlx);
	mlx->map = map;
	ft_draw(map, mlx);
	ft_hookssetup(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
