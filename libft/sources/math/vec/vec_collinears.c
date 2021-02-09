/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_collinears.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:19:08 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:19:09 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	vec_collinears(t_vec u, t_vec v)
{
	double	k;

	if (v.x)
		k = (double)u.x / (double)v.x;
	else if (v.y)
		k = (double)u.y / (double)v.y;
	else if (v.z)
		k = (double)u.z / (double)v.z;
	else
		return (1);
	return (u.x == k * v.x && u.y == k * v.y && u.z == k * v.z);
}
