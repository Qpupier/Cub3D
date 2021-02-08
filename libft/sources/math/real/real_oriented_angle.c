/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_oriented_angle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 23:28:10 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/08 16:45:54 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	real_oriented_angle(t_real u, t_real v)
{
	float	tmp;

	tmp = real_scale_product(u, v);
	if (tmp < -1)
		tmp = -1;
	else if (tmp > 1)
		tmp = 1;
	tmp = acos(tmp);
	if (real_scale_product(real_turn(u, 90), v) < 0)
		return (-1);
	return (1);
}
