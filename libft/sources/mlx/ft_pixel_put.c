/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:56:08 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/19 17:11:13 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pixel_put(t_mlx_img img, int x, int y, uint32_t color)
{
	if (y * img.w + x > img.w * img.h
		|| x < 0 || y < 0 || x >= img.w || y >= img.h)
		return ;
	img.img[(int)(y * img.s_l * 0.25 + x)] = color;
}

void	ft_pixel_put_rgb(t_mlx_img img, int x, int y, t_rgb color)
{
	int	t;

	if (x < 0 || y < 0 || x >= img.w || y >= img.h)
		return ;
	t = y * img.s_l + x * 4;
	img.img[t] = (color.b);
	img.img[t + 1] = (color.g);
	img.img[t + 2] = (color.r);
	img.img[t + 3] = (color.a);
}
