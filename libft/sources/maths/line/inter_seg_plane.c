/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_seg_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:22:38 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/13 14:31:02 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	inter_seg_plane(t_seg s, t_plane p, t_inter_seg_plane *result)
{
	float	t;

	if (!inter_line_plane(line_create_points(s.a, s.b), p,
			&result->result, &t) || !point_line_in_seg(result->result, s))
		return (0);
	result->s1 = vec_equal(result->result, s.a);
	result->s2 = vec_equal(result->result, s.b);
	return (1);
}
