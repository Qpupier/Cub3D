/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:26:51 by slopez            #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cplx	cplx_div(t_cplx a, t_cplx b)
{
	t_cplx r;

	r.rl = (a.rl * b.rl + a.im * b.im) / (ft_sq(b.rl) + ft_sq(b.im));
	r.im = (a.im * b.rl - a.rl * b.im) / (ft_sq(b.rl) + ft_sq(b.im));
	return (r);
}
