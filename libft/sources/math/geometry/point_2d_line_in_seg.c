/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_2d_line_in_seg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:46:42 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 18:09:19 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	point_2d_line_in_seg(t_real p, t_2d_seg s)
{
	if ((p.x < s.a.x || p.x > s.b.x)
		&& (p.x < s.b.x || p.x > s.a.x))
		return (0);
	if ((p.y < s.a.y || p.y > s.b.y)
		&& (p.y < s.b.y || p.y > s.a.y))
		return (0);
	return (1);
}
