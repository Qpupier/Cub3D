/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_opti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:42:18 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/28 18:21:57 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline short	inter_break(float player, float inter)
{
	return (player >= 0 && player < 1 && (inter < 0 || inter >= 1));
}

unsigned char	inter_line_plane_x(t_line l, float d, t_vec *result, float *t)
{
	if (!l.u.x)
		return (0);
	*t = -(l.o.x + d) / l.u.x;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}

unsigned char	inter_line_plane_y(t_line l, float d, t_vec *result, float *t)
{
	if (!l.u.y)
		return (0);
	*t = -(l.o.y + d) / l.u.y;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}

/*static int	inter_line_plane_z(t_line l, t_plane p, t_vec *result, float *t)// INUTILE POUR LE MOMENT
{
	if (!l.u.z)
		return (0);
	*t = -(l.o.z + p.d) / l.u.z;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}*/
