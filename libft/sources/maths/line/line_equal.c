/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:49:00 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/18 18:55:52 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_equal(t_line l1, t_line l2)
{
	if (!vec_collinears(l1.u, l2.u))
		return (0);
	if (!vec_collinears(vec_sub(l1.o, l2.o), l2.u))
		return (0);
	return (1);
}
