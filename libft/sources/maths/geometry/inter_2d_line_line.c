/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_2d_line_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:45:18 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/05 13:46:01 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	inter_2d_line_line(t_2d_line l1, t_2d_line l2, t_real *result)
{
	float	tmp;

	tmp = l1.a * l2.b - l2.a * l1.b;
	if (!tmp)
		return (0);
	tmp = 1 / tmp;
	result->x = (l1.b * l2.c - l2.b * l1.c) * tmp;
	result->y = (l1.c * l2.a - l2.c * l1.a) * tmp;
	return (1);
}
