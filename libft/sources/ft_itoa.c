/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:05:31 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/24 21:33:08 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long int n)
{
	char	*s;
	int		size;

	if (!n)
		return (ft_strdup("0"));
	size = ft_intlen(n);
	s = ft_strnew(size);
	if (!s)
		ft_error("Malloc error");
	while (size--)
	{
		s[size] = ft_digit_abs(n % 10) + '0';
		n /= 10;
	}
	if (*s == '0')
		*s = '-';
	return (s);
}
