/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:41:01 by clynderl          #+#    #+#             */
/*   Updated: 2019/12/11 18:18:16 by clynderl         ###   ########.fr       */
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
	if (!(mlx = ft_mlx_setup(argv[1])))
		return (0);
	ft_map_min_max(map);
	ft_set_size(mlx, map);
	ft_mlx_img_setup(mlx);
	mlx->map = map;
	ft_draw(map, mlx);
	ft_hookssetup(mlx);
	mlx_loop(mlx->mlx_ptr);
	//free(mlx);
	//free(map);
	return (0);
}
