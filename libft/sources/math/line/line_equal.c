/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:49:00 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_equal(t_line l1, t_line l2)
{
	return (vec_collinears(line_vec_dir(l1), line_vec_dir(l2)) && 		\
			vec_collinears(vec_sub(line_point(l1), line_point(l2)), 	\
			line_vec_dir(l2)));
}
