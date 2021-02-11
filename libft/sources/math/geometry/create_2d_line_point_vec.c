/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2d_line_point_vec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:42:11 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2d_line	create_2d_line_point_vec(t_real p1, t_real p2)
{
	float	a;

	if (!p2.x)
		return ((t_2d_line){1, 0, -p1.x});
	a = p2.y / p2.x;
	return ((t_2d_line){a, -1, p1.y - p1.x * a});
}
