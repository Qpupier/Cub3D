/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_sinh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:26:51 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:22:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cplx	cplx_sinh(t_cplx z)
{
	t_cplx	r;

	r.rl = cos(z.im) * (exp(z.rl) - exp(-z.rl)) * 0.5;
	r.im = sin(z.im) * (exp(z.rl) + exp(-z.rl)) * 0.5;
	return (r);
}
