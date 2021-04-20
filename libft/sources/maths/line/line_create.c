/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:32:35 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/18 18:45:56 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_line	line_create_points(t_vec p1, t_vec p2)
{
	return ((t_line){p1, vec_sub(p2, p1)});
}

t_line	line_create_point_vec(t_vec o, t_vec u)
{
	return ((t_line){o, u});
}
