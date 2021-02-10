/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_horiz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:03:43 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:38:48 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_line_horiz(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	float	x1;
	float	y1;
	float	b;
	float	dx;
	float	dy;

	if (a.rl > z.rl)
		cplx_swap(&a, &z);
	x1 = a.rl;
	y1 = a.im;
	dx = z.rl - x1;
	dy = z.im - y1;
	b = y1 - x1 * dy / dx;
	while (z.rl - x1 > 0)
	{
		ft_pixel_put_rgb(img, x1, x1 * dy / dx + b, color);
		if (x1 <= z.rl)
			x1++;
		else
			x1--;
	}
}
