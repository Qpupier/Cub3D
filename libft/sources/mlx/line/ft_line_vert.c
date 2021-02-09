/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_vert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:04:46 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:37:36 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_line_vert(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	float	x1;
	float	y1;
	float	b;
	float	dx;
	float	dy;

	if (a.im > z.im)
		cplx_swap(&a, &z);
	x1 = a.rl;
	y1 = a.im;
	dx = z.rl - x1;
	dy = z.im - y1;
	b = y1 - x1 * dy / dx;
	while (z.im - y1 > 0)
	{
		ft_pixel_put_rgb(img, (y1 - b) * dx / dy, y1, color);
		if (y1 <= z.im)
			y1++;
		else
			y1--;
	}
}
