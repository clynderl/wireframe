/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:12:57 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/26 16:10:26 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_get_color(t_coords curr, t_coords end,
		t_coords start, t_coords delta)
{
	int	colorA[3] = {0, 0, 255};
	int colorB[3] = {255, 0, 0};
	int color[3];
	int i = -1;

	if (end.z > start.z)
	{
		while (++i < 3)
			color[i] = colorA[i] + 0.5 * (colorB[i] - colorA[i]);
	}
	(void)curr;
	(void)end;
	(void)start;
	(void)delta;
	return (0x7f007f);
}
