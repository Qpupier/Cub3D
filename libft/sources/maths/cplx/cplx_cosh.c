/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_cosh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:59:09 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:22:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cplx	cplx_cosh(t_cplx z)
{
	t_cplx	r;

	r.rl = cos(z.im) * (exp(z.rl) + exp(-z.rl)) / 2;
	r.im = sin(z.im) * (exp(z.rl) - exp(-z.rl)) / 2;
	return (r);
}
