/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_straight.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:07:18 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:39:02 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_line_straight(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	if (a.rl == z.rl)
		return (ft_line_straight_vert(img, a, z, color));
	else if (a.im == z.im)
		return (ft_line_straight_horiz(img, a, z, color));
	return (0);
}
