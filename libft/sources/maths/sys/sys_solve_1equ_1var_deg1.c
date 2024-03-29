/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_solve_1equ_1var_deg1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:55:12 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:11:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sys_solve_1equ_1var_deg1(float a, float b, t_sys_sol_1var_deg1 *s)
{
	if (!a)
		return (0);
	s->x = -b / a;
	return (1);
}
