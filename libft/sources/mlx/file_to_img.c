/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:49:56 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:49:38 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	xpm_to_img(void *mlx_ptr, t_mlx_img *img, char *file)
{
	img->ptr = mlx_xpm_file_to_image(mlx_ptr, file, &img->w, &img->h);
	if (!img->ptr)
	{
		ft_putstr("Fail to load image : ");
		ft_putendl(file);
		return (0);
	}
	img->img = (unsigned int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->s_l,
			&img->end);
	if (!img->img)
	{
		ft_putstr("Fail to load image : ");
		ft_putendl(file);
		free(img->ptr);
		return (0);
	}
	return (1);
}

int	png_to_img(void *mlx_ptr, t_mlx_img *img, char *file)
{
	img->ptr = mlx_png_file_to_image(mlx_ptr, file, &img->w, &img->h);
	if (!img->ptr)
	{
		ft_putstr("Fail to load img : ");
		ft_putendl(file);
		return (0);
	}
	img->img = (unsigned int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->s_l,
			&img->end);
	if (!img->img)
	{
		ft_putstr("Fail to load img : ");
		ft_putendl(file);
		free(img->ptr);
		return (0);
	}
	return (1);
}
