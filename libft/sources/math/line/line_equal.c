/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:49:00 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 18:21:13 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_equal(t_line l1, t_line l2)
{
	if (!vec_collinears(line_vec_dir(l1), line_vec_dir(l2)))
		return (0);
	if (!vec_collinears(vec_sub(line_point(l1), line_point(l2)),
			line_vec_dir(l2)))
		return (0);
	return (1);
}
