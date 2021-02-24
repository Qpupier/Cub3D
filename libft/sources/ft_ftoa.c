/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:27:28 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/24 21:45:17 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ftoa_tmp(int nb, int p, char *s)
{
	char	*t;

	nb += 5.0 / ft_pow(10, p + 1);
	t = ft_itoa(nb);
	ft_strcat(s, t);
	ft_strdel(&t);
	if (p)
		ft_strcat(s, ".");
	while (p--)
	{
		nb -= (int)nb;
		t = ft_itoa((nb *= 10));
		ft_strcat(s, t);
		ft_strdel(&t);
	}
	return (s);
}

char	*ft_ftoa(float nb, int p)
{
	char	*s;

	if (p < 0)
		p = 0;
	if (p)
		s = ft_strnew(ft_intlen(nb) + p + 1);
	else
		s = ft_strnew(ft_intlen(nb) + p);
	if (!s)
		ft_error("Malloc error");
	if (nb < 0)
	{
		ft_strcat(s, "-");
		nb = -nb;
	}
	return (ft_ftoa_tmp(nb, p, s));
}
