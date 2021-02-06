/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_sin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:26:51 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 17:58:23 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	cplx_sin(t_cplx z)
{
	t_cplx	r;

	r.rl = sin(z.rl) * (exp(z.im) + exp(-z.im)) * 0.5;
	r.im = cos(z.rl) * (exp(z.im) - exp(-z.im)) * 0.5;
	return (r);
}
