/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:45:04 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:15:04 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_rot_x(t_vec v, float rad)
{
	t_vec	new;

	new.x = v.x;
	new.y = v.y * cos(rad) + v.z * -sin(rad);
	new.z = v.y * sin(rad) + v.z * cos(rad);
	return (new);
}

inline t_vec	vec_rot_y(t_vec v, float rad)
{
	t_vec	new;

	new.x = v.x * cos(rad) + v.z * sin(rad);
	new.y = v.y;
	new.z = v.x * -sin(rad) + v.z * cos(rad);
	return (new);
}

inline t_vec	vec_rot_z(t_vec v, float rad)
{
	t_vec	new;

	new.x = v.x * cos(rad) + v.y * -sin(rad);
	new.y = v.x * sin(rad) + v.y * cos(rad);
	new.z = v.z;
	return (new);
}
