/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:51:39 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_check(t_line l, int nb_points, t_vec *points, t_vec per)
{
	int		i;
	t_vec	point;
	int		nb_n;
	int		nb_p;
	float	tmp;

	point = line_point(l);
	nb_n = 0;
	nb_p = 0;
	i = -1;
	while (++i < nb_points)
		if ((tmp = vec_scale_product(per, vec_sub(points[i], point))) < 0)
			nb_n++;
		else if (tmp > 0)
			nb_p++;
	return (!nb_n || !nb_p);
}
