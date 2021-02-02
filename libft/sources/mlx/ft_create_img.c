/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:57:48 by qpupier           #+#    #+#             */
/*   Updated: 2021/01/21 12:08:17 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_create_img(void *ptr, t_mlx_img *img, int w, int h)
{
	if (!(img->ptr = mlx_new_image(ptr, w, h)))
		ft_error("Minilibx error - Imossible to create an image");
	if (!(img->img = (unsigned int *)mlx_get_data_addr(img->ptr, 	\
			&img->bpp, &img->s_l, &img->end)))
		ft_error("Minilibx error - Impossible to get image data");
	img->w = w;
	img->h = h;
}
