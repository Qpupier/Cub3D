/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:53:57 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_move_x(t_vec v, float mov)
{
	v.x += mov;
	return (v);
}

inline t_vec	vec_move_y(t_vec v, float mov)
{
	v.y += mov;
	return (v);
}

inline t_vec	vec_move_z(t_vec v, float mov)
{
	v.z += mov;
	return (v);
}
