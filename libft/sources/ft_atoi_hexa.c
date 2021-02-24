/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:26:40 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/24 21:44:26 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_hexa_tmp(const char *str, int i)
{
	long	result;

	result = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F')))
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = 16 * result + str[i++] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = 16 * result + str[i++] - 'a' + 10;
		else
			result = 16 * result + str[i++] - 'A' + 10;
	}
	return (result);
}

int	ft_atoi_hexa(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = ft_atoi_hexa_tmp(str, i);
	if (result < 0 && sign < 0)
		return (0);
	if (result < 0)
		return (-1);
	return (result * sign);
}
