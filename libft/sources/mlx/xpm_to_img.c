/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:49:56 by qpupier           #+#    #+#             */
/*   Updated: 2021/01/12 17:29:19 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	xpm_to_img(void *ptr, t_mlx_img *img, char *file)
{
	if (!(img->ptr = 														\
			mlx_xpm_file_to_image(ptr, file, &img->width, &img->height)) 	\
			|| !(img->img = 												\
			(unsigned int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->s_l, &img->endian)))
		ft_error(ft_strjoin("Fail to load img : ", file));
}
