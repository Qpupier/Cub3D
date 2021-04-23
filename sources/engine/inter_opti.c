/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_opti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:42:18 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/23 09:43:03 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	inter_line_plane_x(t_line l, t_plane p, t_vec *result, float *t)
{
	if (!l.u.x)
		return (0);
	*t = -(l.o.x + p.d) / l.u.x;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}

int	inter_line_plane_y(t_line l, t_plane p, t_vec *result, float *t)
{
	if (!l.u.y)
		return (0);
	*t = -(l.o.y + p.d) / l.u.y;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}

/*static int	inter_line_plane_z(t_line l, t_plane p, t_vec *result, float *t)
{
	if (!l.u.z)
		return (0);
	*t = -(l.o.z + p.d) / l.u.z;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}*/
