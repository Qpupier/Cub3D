/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_line_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:20:30 by slopez            #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		inter_line_plane(t_line l, t_plane p, t_vec *result)
{
	float	tmp;
	float	t;

	if (!(tmp = p.a * l.x.u + p.b * l.y.u + p.c * l.z.u))
		return (0);
	t = -(p.a * l.x.o + p.b * l.y.o + p.c * l.z.o + p.d) / tmp;
	*result = vec_add((t_vec){l.x.o, l.y.o, l.z.o}, 	\
			vec_mult_float((t_vec){l.x.u, l.y.u, l.z.u}, t));
	return (1);
}
