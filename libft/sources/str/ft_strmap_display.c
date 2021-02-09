/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:19:37 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:22:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_strmap_display(char *str, int l, int h)
{
	int i;
	int j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < l)
			ft_putchar(str[i * h + j]);
		write(1, "\n", 1);
	}
}
