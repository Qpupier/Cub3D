/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_solve_1equ_1var_deg2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:29:48 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/07 15:51:53 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sys_solve_1equ_1var_deg2_tmp(t_equ_1var_deg2 e, 	\
		t_sys_sol_1var_deg2 *s)
{
	t_sys_sol_1var_deg1	sol;
	int					result;

	s->s1 = 0;
	s->s2 = 0;
	s->x1 = 0;
	s->x2 = 0;
	if (!e.a && !e.b)
		return (0);
	if (!e.a)
	{
		result = sys_solve_1equ_1var_deg1(e.b, e.c, &sol);
		if (!result)
			return (0);
		s->s1 = 1;
		s->x1 = sol.x;
		return (1);
	}
	return (-1);
}

int			sys_solve_1equ_1var_deg2(t_equ_1var_deg2 e, t_sys_sol_1var_deg2 *s)
{
	float	delta;
	float	tmp;
	float	sqrt_delta;

	if ((tmp = sys_solve_1equ_1var_deg2_tmp(e, s)) != -1)
		return (tmp);
	delta = ft_sq(e.b) - 4 * e.a * e.c;
	tmp = 1 / (2 * e.a);
	if (delta < 0)
		return (0);
	else if (!delta)
	{
		s->s1 = 1;
		s->x1 = -e.b * tmp;
		return (1);
	}
	sqrt_delta = sqrtf(delta);
	s->s1 = 1;
	s->s2 = 1;
	s->x1 = (-e.b - sqrt_delta) * tmp;
	s->x2 = (-e.b + sqrt_delta) * tmp;
	return (2);
}
