/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:02:08 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/18 18:44:33 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	proj_point_plane(t_vec point, t_plane plane, float *dist)
{
	float	tmp;
	t_vec	result;

	tmp = plane.a * plane.a + plane.b * plane.b + plane.c * plane.c;
	if (!tmp)
		ft_error("Plane error");
	result = vec_mult_float((t_vec){plane.a, plane.b, plane.c},
			(-plane.a * point.x - plane.b * point.y - plane.c * point.z
				- plane.d) / tmp);
	*dist = vec_norm(result);
	return (vec_add(point, result));
}

t_vec	proj_point_seg(t_vec p, t_seg s, float *dist)
{
	t_vec	result;
	float	dist1;
	float	dist2;

	result = proj_point_line(p, line_create_points(s.a, s.b), dist);
	if (!point_line_in_seg(result, s))
	{
		dist1 = vec_norm(vec_sub(s.a, p));
		dist2 = vec_norm(vec_sub(s.b, p));
		if (dist1 < dist2)
		{
			*dist = dist1;
			result = s.a;
		}
		else
		{
			*dist = dist2;
			result = s.b;
		}
	}
	return (result);
}

t_vec	proj_point_line(t_vec p, t_line l, float *dist)
{
	float	t;
	t_vec	result;

	t = vec_scale_product(vec_sub(p, l.o), vec_normalize(l.u));
	result = vec_add(l.o, vec_mult_float(l.u, t));
	*dist = vec_norm(vec_sub(result, p));
	return (result);
}
