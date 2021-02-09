/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 23:26:16 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/08 16:46:19 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_real	real_normalize(t_real v)
{
	float	tmp;

	tmp = real_norm(v);
	if (!tmp)
		return ((t_real){0, 0});
	tmp = 1 / tmp;
	v.x *= tmp;
	v.y *= tmp;
	return (v);
}
