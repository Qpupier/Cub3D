/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:36:11 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	vec_equal(t_vec u, t_vec v)
{
	return (u.x == v.x && u.y == v.y && u.z == v.z);
}

inline int	vec_equal_precision(t_vec u, t_vec v, float p)
{
	return (floatcmp(u.x, v.x, p) && floatcmp(u.y, v.y, p)
			&& floatcmp(u.z, v.z, p));
}
