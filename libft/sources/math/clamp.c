/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:00:16 by slopez            #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		fclamp(float *curr, float min, float max)
{
	if (*curr <= min)
		*curr = min;
	if (*curr >= max)
		*curr = max;
}

void		iclamp(intmax_t *curr, int min, int max)
{
	if (*curr <= min)
		*curr = min;
	if (*curr >= max)
		*curr = max;
}
