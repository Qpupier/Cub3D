/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:14:56 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/03 14:22:04 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline t_vec	vec_rot_x_pre(t_param *p, t_vec v, int angle)
{
	t_vec	new;

	new.x = v.x;
	new.y = v.y * p->trigo_cos[angle] + v.z * -p->trigo_sin[angle];
	new.z = v.y * p->trigo_sin[angle] + v.z * p->trigo_cos[angle];
	return (new);
}

inline t_vec	vec_rot_z_pre(t_param *p, t_vec v, int angle)
{
	t_vec	new;

	new.x = v.x * p->trigo_cos[angle] + v.y * -p->trigo_sin[angle];
	new.y = v.x * p->trigo_sin[angle] + v.y * p->trigo_cos[angle];
	new.z = v.z;
	return (new);
}
