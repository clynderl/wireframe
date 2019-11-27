/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:49:02 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/27 13:12:22 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_min_max(t_map *map)
{
	int i;
	int j;
	int min;
	int max;

	min = map->tab[0][0];
	max = map->tab[0][0];
	j = 0;
	while (j < map->cols)
	{
		i = 0;
		while (i < map->rows)
		{
			if (min > map->tab[j][i])
				min = map->tab[j][i];
			if (max < map->tab[j][i])
				max = map->tab[j][i];
			i++;
		}
		j++;
	}
	map->z_min = min;
	map->z_max = max;
}
