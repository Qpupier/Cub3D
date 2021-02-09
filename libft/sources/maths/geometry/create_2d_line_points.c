/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2d_line_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:11:57 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 18:12:24 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2d_line	create_2d_line_points(t_real p1, t_real p2)
{
	float	a;
	float	tmp;
	t_real	pt;

	tmp = p2.x - p1.x;
	if (!tmp)
		return ((t_2d_line){1, 0, -p1.x});
	a = (p2.y - p1.y) / tmp;
	pt = p1;
	if (fabsf(p1.x + p1.y) * 0.5 > fabsf(p2.x + p2.y) * 0.5)
		pt = p2;
	return ((t_2d_line){a, -1, pt.y - pt.x * a});
}
