/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_real_to_cplx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:13:59 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 17:50:19 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_real_to_cplx(t_real xy)
{
	t_cplx	r;

	r.rl = xy.x;
	r.im = xy.y;
	return (r);
}
