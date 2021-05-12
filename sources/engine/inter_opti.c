/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_opti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:42:18 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/12 18:40:57 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

// static int	inter_line_plane_z(t_line l, float d, t_vec *result, float *t)// INUTILE POUR LE MOMENT
// {
// 	if (!l.u.z)
// 		return (0);
// 	*t = -(l.o.z + d) / l.u.z;
// 	*result = vec_add(l.o, vec_mult_float(l.u, *t));
// 	return (1);
// }

float	intersec_plane_c(t_param *p, t_line line, float *r_w, float *r_h)
{
	t_vec	result;
	float	t;

	if (!line.u.z)
		return (-1);
	t = (1 - line.o.z) / line.u.z;
	if (t < 0)
		return (-1);
	result = vec_add(line.o, vec_mult_float(line.u, t));
	if (result.x >= 0 && result.x < p->map->w && result.y >= 0 && result.y < p->map->h && (!p->ceil || p->map->map[(int)result.y][(int)result.x]))
	{
		*r_w = result.x - (int)result.x;
		*r_h = result.y - (int)result.y;
		return (t);
	}
	return (-1);
}

float	intersec_plane_f(t_param *p, t_line line, float *r_w, float *r_h)
{
	t_vec	result;
	float	t;

	if (!line.u.z)
		return (-1);
	t = -line.o.z / line.u.z;
	if (t < 0)
		return (-1);
	result = vec_add(line.o, vec_mult_float(line.u, t));
	if (result.x >= 0 && result.x < p->map->w && result.y >= 0 && result.y < p->map->h)
	{
		*r_w = result.x - (int)result.x;
		*r_h = result.y - (int)result.y;
		return (t);
	}
	return (-1);
}
