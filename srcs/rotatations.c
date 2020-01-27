/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:31:16 by clynderl          #+#    #+#             */
/*   Updated: 2020/01/27 16:49:36 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_iso(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.615472907);
	*y = -z + (prev_x + prev_y) * sin(0.615472907);
}

void	ft_rotatation_x(int *y, double *z, double a)
{
	int p_y;

	p_y = *y;
	*y = p_y * cos(a) + *z * sin(a);
	*z = -p_y * sin(a) + *z * cos(a);
}

void	ft_rotatation_y(int *x, double *z, double b)
{
	int p_x;

	p_x = *x;
	*x = p_x * cos(b) + *z * sin(b);
	*z = -p_x * sin(b) + *z * cos(b);
}

void	ft_rotatation_z(int *x, int *y, double g)
{
	int p_x;
	int p_y;

	p_x = *x;
	p_y = *y;
	*x = p_x * cos(g) - p_y * sin(g);
	*y = p_x * sin(g) + p_y * cos(g);
}
