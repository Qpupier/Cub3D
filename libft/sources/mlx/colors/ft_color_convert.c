/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:30:15 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/14 17:09:20 by qpupier          ###   ########lyon.fr   */
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

inline unsigned int	rgb_to_hex(t_rgb c)
{
	return (c.a << 24 | c.r << 16 | c.g << 8 | c.b);
}
