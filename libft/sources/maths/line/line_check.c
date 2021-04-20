/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:51:39 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/18 18:55:10 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_check(t_line l, int nb_points, t_vec *points, t_vec per)
{
	int		i;
	int		nb_n;
	int		nb_p;
	float	tmp;

	nb_n = 0;
	nb_p = 0;
	i = -1;
	while (++i < nb_points)
	{
		tmp = vec_scale_product(per, vec_sub(points[i], l.o));
		if (tmp < 0)
			nb_n++;
		else if (tmp > 0)
			nb_p++;
	}
	return (!nb_n || !nb_p);
}
