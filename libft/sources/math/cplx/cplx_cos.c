/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_cos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:59:20 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 18:00:22 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	cplx_cos(t_cplx z)
{
	t_cplx	r;

	r.rl = cos(z.rl) * (exp(z.im) + exp(-z.im)) / 2;
	r.im = -sin(z.rl) * (exp(z.im) - exp(-z.im)) / 2;
	return (r);
}
