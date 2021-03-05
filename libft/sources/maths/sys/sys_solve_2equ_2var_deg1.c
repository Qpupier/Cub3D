/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_solve_2equ_2var_deg1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:11:38 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/05 13:46:18 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sys_solve_2equ_2var_deg1(t_equ_2var_deg1 e1, t_equ_2var_deg1 e2, 	\
		t_sys_sol_2var_deg1 *s)
{
	float	tmp;

	tmp = e2.a_x * e1.a_y - e1.a_x * e2.a_y;
	if (!tmp)
		return (0);
	tmp = 1 / tmp;
	s->x = (e2.a_y * e1.b - e1.a_y * e2.b) * tmp;
	s->y = (e1.a_x * e2.b - e2.a_x * e1.b) * tmp;
	return (1);
}
