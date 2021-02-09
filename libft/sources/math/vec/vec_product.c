/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:15:19 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:15:21 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_cross_product(t_vec u, t_vec v)
{
	t_vec	n;

	n.x = u.y * v.z - u.z * v.y;
	n.y = u.z * v.x - u.x * v.z;
	n.z = u.x * v.y - u.y * v.x;
	return (n);
}

inline float	vec_scale_product(t_vec u, t_vec v)
{
	return (fmaf(u.x, v.x, fmaf(u.y, v.y, fmaf(u.z, v.z, 0))));
}
