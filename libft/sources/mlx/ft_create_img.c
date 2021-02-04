/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:57:48 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/04 10:38:31 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_create_img(void *ptr, t_mlx_img *img, int w, int h)
{
	if (!(img->ptr = mlx_new_image(ptr, w, h)))
		return (0);
	if (!(img->img = (unsigned int *)mlx_get_data_addr(img->ptr, 	\
			&img->bpp, &img->s_l, &img->end)))
		return (0);
	img->w = w;
	img->h = h;
	return (1);
}
