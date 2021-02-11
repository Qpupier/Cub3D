/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2d_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:48:39 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2d_ray	create_2d_ray(t_real a, t_real b)
{
	t_2d_ray	new;
	t_2d_line	line;

	new.o = a;
	new.d = op_real(a, '>', b);
	line = create_2d_line_points(a, b);
	new.a = line.a;
	new.b = line.b;
	new.c = line.c;
	return (new);
}
