/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_arraycpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:46:48 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/08 16:47:28 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	real_arraycpy(t_real *src, t_real *dest, unsigned int nb)
{
	unsigned int	i;

	i = -1;
	while (++i < nb)
	{
		dest[i].x = src[i].x;
		dest[i].y = src[i].y;
	}
}
