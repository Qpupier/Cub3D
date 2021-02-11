/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:26:11 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char *s, char c)
{
	int	j;
	int	nb;

	nb = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s++ != c)
			j++;
		if (j)
			nb++;
		while (*s == c)
			s++;
	}
	return (nb);
}
