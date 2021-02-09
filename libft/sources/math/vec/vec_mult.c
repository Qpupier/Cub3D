/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:16:10 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:16:12 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_mult_float(t_vec vec, float f)
{
	vec.x *= f;
	vec.y *= f;
	vec.z *= f;
	return (vec);
}
