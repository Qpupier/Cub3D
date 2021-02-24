/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:28:27 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/24 21:32:47 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(const char *str)
{
	float	res;
	char	*c;

	c = (char *)str;
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res = (float)ft_atoi(c) / pow(10, ft_strlen(c));
	if ((float)ft_atoi(str) + (*str == '-'))
		return (-res);
	return (res);
}
