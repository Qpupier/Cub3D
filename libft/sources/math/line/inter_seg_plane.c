/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_seg_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:20:48 by slopez            #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		inter_seg_plane(t_seg s, t_plane p, t_inter_seg_plane *result)
{
	if (!inter_line_plane(line_create_points(s.a, s.b), p, 	\
			&result->result) || !point_line_in_seg(result->result, s))
		return (0);
	result->s1 = vec_equal(result->result, s.a);
	result->s2 = vec_equal(result->result, s.b);
	return (1);
}
