/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_average.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:59:25 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 17:59:26 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	cplx_average(t_cplx a, t_cplx z, float b)
{
	return (cplx_make(a.rl + b * (z.rl - a.rl), a.im + b * (z.im - a.im)));
}
