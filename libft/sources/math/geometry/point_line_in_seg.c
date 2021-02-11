/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_line_in_seg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:19:53 by slopez            #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		point_line_in_seg(t_vec p, t_seg s)
{
	return (((p.x >= s.a.x && p.x <= s.b.x) 		\
				|| (p.x >= s.b.x && p.x <= s.a.x)) 	\
			&& ((p.y >= s.a.y && p.y <= s.b.y) 		\
				|| (p.y >= s.b.y && p.y <= s.a.y)) 	\
			&& ((p.z >= s.a.z && p.z <= s.b.z) 		\
				|| (p.z >= s.b.z && p.z <= s.a.z)));
}
