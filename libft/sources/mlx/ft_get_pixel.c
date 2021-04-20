/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:59:42 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/19 17:14:35 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_get_pixel(t_mlx_img img, int x, int y)
{
	int	w;
	int	tmp;

	w = img.s_l * 0.25;
	tmp = y * w + x;
	if (tmp > w * img.h || x < 0 || y < 0 || x >= img.w || y >= img.h)
		return (-1);
	return (img.img[tmp]);
}
