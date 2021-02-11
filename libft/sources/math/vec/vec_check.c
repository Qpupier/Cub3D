/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:58:47 by slopez            #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec			vec_check(t_vec src)
{
	t_vec		dst;

	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
	src.x = fabs(src.x);
	src.y = fabs(src.y);
	src.z = fabs(src.z);
	if (src.x <= 0.005)
		dst.x = 0.f;
	if (src.y <= 0.005)
		dst.y = 0.f;
	if (src.z <= 0.005)
		dst.z = 0.f;
	return (dst);
}
