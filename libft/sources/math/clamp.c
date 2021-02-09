/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:26:11 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:26:18 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fclamp(float *curr, float min, float max)
{
	if (*curr <= min)
		*curr = min;
	if (*curr >= max)
		*curr = max;
}

void	iclamp(intmax_t *curr, int min, int max)
{
	if (*curr <= min)
		*curr = min;
	if (*curr >= max)
		*curr = max;
}
