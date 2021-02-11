/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:52:27 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_real	real_turn(t_real point, float degree)
{
	t_real	new;

	degree = ft_deg_to_rad(degree);
	new.x = cos(degree) * point.x - sin(degree) * point.y;
	new.y = sin(degree) * point.x + cos(degree) * point.y;
	return (new);
}
