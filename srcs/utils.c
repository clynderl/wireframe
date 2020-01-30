/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:49:02 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/27 17:29:00 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->rows)
	{
		free(map->tab[i]);
		free(map->colors[i]);
		i++;
	}
	free(map);
	return (0);
}

int		ft_map_min_max(t_map *map)
{
	int i;
	int j;

	map->z_min = map->tab[0][0];
	map->z_max = map->tab[0][0];
	j = 0;
	while (j < map->cols)
	{
		if (map->tab[j] == NULL)
			return (ft_free_map(map));
		i = 0;
		while (i < map->rows)
		{
			if (map->z_min > map->tab[j][i])
				map->z_min = map->tab[j][i];
			if (map->z_max < map->tab[j][i])
				map->z_max = map->tab[j][i];
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_is_digit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, int base)
{
	unsigned long	result;
	int				sign;
	int				i;

	result = 0;
	i = 0;
	sign = 1;
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i++] == '-') ? -1 : 1;
	while (ft_is_digit_base(str[i], base) >= 0)
		result = result * base + ft_is_digit_base(str[i++], base);
	return ((int)(result * sign));
}
