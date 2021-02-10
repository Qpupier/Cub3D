/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_int_to_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:29:38 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:29:41 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	ft_color_int_to_rgb(int nb)
{
	t_rgb	rgb;

	rgb.r = nb / 65536;
	rgb.g = nb / 256 % 256;
	rgb.b = nb % 256;
	rgb.a = 0;
	return (rgb);
}
