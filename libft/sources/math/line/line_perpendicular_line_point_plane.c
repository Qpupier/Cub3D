/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_perpendicular_line_point_plane.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:44:47 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_line	line_perpendicular_line_point_plane(t_line l, t_vec p, t_vec n)
{
	return (line_create_point_vec(p, vec_cross_product(n, line_vec_dir(l))));
}
