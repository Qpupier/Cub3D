/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_array_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:19:34 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:19:39 by qpupier          ###   ########lyon.fr   */
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
