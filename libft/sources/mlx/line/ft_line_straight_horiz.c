/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_straight_horiz.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:06:42 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:22:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int		ft_line_straight_horiz(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	int	x1;

	x1 = a.rl;
	while (ft_abs(z.rl - x1) >= 1)
	{
		ft_pixel_put_rgb(img, x1, a.im, color);
		x1 < z.rl ? x1++ : x1--;
	}
	return (1);
}
