/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_line_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:23:08 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/18 18:53:23 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	inter_line_plane(t_line l, t_plane p, t_vec *result, float *t)
{
	float	tmp;

	tmp = p.a * l.u.x + p.b * l.u.y + p.c * l.u.z;
	if (!tmp)
		return (0);
	*t = - (p.a * l.o.x + p.b * l.o.y + p.c * l.o.z + p.d) / tmp;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}
