/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_color_complete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:09:18 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/05 13:47:44 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hex_color_complete(char *c)
{
	int		i;
	char	*color;
	char	tmp;

	if (!c)
		return (ft_strdup("0xFFFFFF00"));
	color = (char *)malloc(sizeof(*color) * 11);
	if (!color)
		ft_error("Malloc error");
	i = -1;
	while (++i < 10 && c[i])
		color[i] = c[i];
	tmp = c[--i];
	while (++i < 10)
	{
		if (i < 8)
			color[i] = tmp;
		else
			color[i] = '0';
	}
	color[i] = '\0';
	return (color);
}
