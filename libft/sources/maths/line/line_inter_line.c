/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_inter_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:17:46 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/18 18:50:01 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	line_inter_line__2(t_line l1, t_line l2, t_vec *result)
{
	t_sys_sol_2var_deg1	s;
	int					stop;

	stop = 0;
	if (!stop && l1.u.y && l2.u.z)
		stop = sys_solve_2equ_2var_deg1(
				(t_equ_2var_deg1){l1.u.y, -l2.u.y, l1.o.y - l2.o.y},
				(t_equ_2var_deg1){l1.u.z, -l2.u.z, l1.o.z - l2.o.z}, &s);
	if (!stop && l1.u.z && l2.u.x)
		stop = sys_solve_2equ_2var_deg1(
				(t_equ_2var_deg1){l1.u.z, -l2.u.z, l1.o.z - l2.o.z},
				(t_equ_2var_deg1){l1.u.x, -l2.u.x, l1.o.x - l2.o.x}, &s);
	if (!stop && l1.u.z && l2.u.y)
		stop = sys_solve_2equ_2var_deg1(
				(t_equ_2var_deg1){l1.u.z, -l2.u.z, l1.o.z - l2.o.z},
				(t_equ_2var_deg1){l1.u.y, -l2.u.y, l1.o.y - l2.o.y}, &s);
	if (stop)
		*result = vec_create(l1.o.x + l1.u.x * s.x,
				l1.o.y + l1.u.y * s.x, l1.o.z + l1.u.z * s.x);
	return (stop);
}

int	line_inter_line(t_line l1, t_line l2, t_vec *result)
{
	t_sys_sol_2var_deg1	s;
	int					stop;

	stop = 0;
	if (l1.u.x && l2.u.y)
		stop = sys_solve_2equ_2var_deg1(
				(t_equ_2var_deg1){l1.u.x, -l2.u.x, l1.o.x - l2.o.x},
				(t_equ_2var_deg1){l1.u.y, -l2.u.y, l1.o.y - l2.o.y}, &s);
	if (!stop && l1.u.x && l2.u.z)
		stop = sys_solve_2equ_2var_deg1(
				(t_equ_2var_deg1){l1.u.x, -l2.u.x, l1.o.x - l2.o.x},
				(t_equ_2var_deg1){l1.u.z, -l2.u.z, l1.o.z - l2.o.z}, &s);
	if (!stop && l1.u.y && l2.u.x)
		stop = sys_solve_2equ_2var_deg1(
				(t_equ_2var_deg1){l1.u.y, -l2.u.y, l1.o.y - l2.o.y},
				(t_equ_2var_deg1){l1.u.x, -l2.u.x, l1.o.x - l2.o.x}, &s);
	if (stop)
		*result = vec_create(l1.o.x + l1.u.x * s.x,
				l1.o.y + l1.u.y * s.x, l1.o.z + l1.u.z * s.x);
	else
		stop = line_inter_line__2(l1, l2, result);
	return (stop);
}
