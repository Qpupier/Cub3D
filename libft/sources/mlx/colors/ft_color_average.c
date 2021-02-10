/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_average.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:30:21 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:30:44 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	ft_color_average(t_rgb c1, t_rgb c2, float p)
{
	t_rgb	rgb;

	rgb.r = c1.r + (c2.r - c1.r) * p;
	rgb.g = c1.g + (c2.g - c1.g) * p;
	rgb.b = c1.b + (c2.b - c1.b) * p;
	rgb.a = c1.a + (c2.a - c1.a) * p;
	return (rgb);
}

int	color_avg_calc(int start, int end, double percentage)
{
	return ((int)((1 - percentage) *start + percentage * end));
}

int	color_avg(unsigned int s_col, unsigned int end_col, double p)
{
	short int	red;
	short int	green;
	short int	blue;

	if (p >= 1)
		p = 1;
	if (p <= 0)
		p = 0;
	red = color_avg_calc((s_col >> 16) & 0xFF, (end_col >> 16) & 0xFF, p);
	green = color_avg_calc((s_col >> 8) & 0xFF, (end_col >> 8) & 0xFF, p);
	blue = color_avg_calc(s_col & 0xFF, end_col & 0xFF, p);
	return ((red << 16) | (green << 8) | (blue));
}
