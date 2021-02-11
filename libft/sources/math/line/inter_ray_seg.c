/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_ray_seg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:23:07 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	inter_ray_seg(t_ray l, t_seg s, t_vec *result)
{
	float	d_s;
	float	d_l;
	float	d_s1;
	float	d_s2;

	if (!line_inter_line(line_create_point_vec(l.o, l.d), 	\
			line_create_points(s.a, s.b), result))
		return (0);
	d_l = vec_scale_product(vec_sub(*result, l.o), l.d);
	d_s = vec_norm(vec_sub(s.b, s.a));
	d_s1 = vec_norm(vec_sub(*result, s.a));
	d_s2 = vec_norm(vec_sub(*result, s.b));
	if (d_l < 0 || d_s1 > d_s || d_s2 > d_s)
		return (0);
	if (!d_l)
		return (2);
	if (d_s1 == d_s || d_s2 == d_s)
		return (3);
	return (1);
}
