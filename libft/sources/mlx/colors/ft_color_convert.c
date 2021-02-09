/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:30:15 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:31:14 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	hex_to_rgb(unsigned int color)
{
	t_rgb	c;

	c.a = color >> 24 & 0xFF;
	c.g = color >> 16 & 0xFF;
	c.b = color >> 8 & 0xFF;
	c.r = color & 0xFF;
	return (c);
}

unsigned int	rgb_to_hex(t_rgb c)
{
	return ((c.a << 24) | (c.g << 16) | (c.b << 8) | (c.r));
}
