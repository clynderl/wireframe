/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:49:02 by clynderl          #+#    #+#             */
/*   Updated: 2019/12/11 15:28:05 by clynderl         ###   ########.fr       */
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
