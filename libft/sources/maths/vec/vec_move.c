/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:16:19 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:16:20 by qpupier          ###   ########lyon.fr   */
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
