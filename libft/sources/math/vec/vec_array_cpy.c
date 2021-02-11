/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_array_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:06:31 by slopez            #+#    #+#             */
/*   Updated: 2020/04/12 21:29:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tvec_array_cpy(t_vec *in, t_vec *out, unsigned int nb)
{
	unsigned int	i;

	i = -1;
	while (++i < nb)
		out[i] = in[i];
}
