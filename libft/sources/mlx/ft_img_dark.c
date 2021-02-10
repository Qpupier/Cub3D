/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_dark.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:00:17 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:42:53 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_img_dark(t_mlx_img img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < img.h)
	{
		i = -1;
		while (++i < img.w)
			ft_pixel_put_rgb(img, i, j, (t_rgb){0, 0, 0, 0});
	}
}
