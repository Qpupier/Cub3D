/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_line_in_seg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:03:33 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 18:07:24 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	point_line_in_seg(t_vec p, t_seg s)
{
	if ((p.x < s.a.x || p.x > s.b.x)
		&& (p.x < s.b.x || p.x > s.a.x))
		return (0);
	if ((p.y < s.a.y || p.y > s.b.y)
		&& (p.y < s.b.y || p.y > s.a.y))
		return (0);
	if ((p.z < s.a.z || p.z > s.b.z)
		&& (p.z < s.b.z || p.z > s.a.z))
		return (0);
	return (1);
}
