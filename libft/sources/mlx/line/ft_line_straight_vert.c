/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_straight_vert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:05:32 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:22:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int		ft_line_straight_vert(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	int	y1;

	y1 = a.im;
	while (ft_abs(z.im - y1) >= 1)
	{
		ft_pixel_put_rgb(img, a.rl, y1, color);
		y1 < z.im ? y1++ : y1--;
	}
	return (1);
}
