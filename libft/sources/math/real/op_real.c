/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_real.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:44:16 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_real	op_real(t_real a, char op, t_real b)
{
	if (op == '+')
		return ((t_real){a.x + b.x, a.y + b.y});
	if (op == '-')
		return ((t_real){a.x - b.x, a.y - b.y});
	if (op == '>')
		return (op_real(b, '-', a));
	return ((t_real){0, 0});
}
