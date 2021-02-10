/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_hex_to_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:29:48 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:29:51 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	ft_color_hex_to_rgb(char *color)
{
	t_rgb	rgb;

	color = ft_hex_color_complete(color);
	rgb.r = ft_digit_hex_to_int(color[2]) * 16 + ft_digit_hex_to_int(color[3]);
	rgb.g = ft_digit_hex_to_int(color[4]) * 16 + ft_digit_hex_to_int(color[5]);
	rgb.b = ft_digit_hex_to_int(color[6]) * 16 + ft_digit_hex_to_int(color[7]);
	rgb.a = ft_digit_hex_to_int(color[8]) * 16 + ft_digit_hex_to_int(color[9]);
	if (color)
		ft_strdel(&color);
	return (rgb);
}
