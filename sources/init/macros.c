/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:58:56 by qpupier           #+#    #+#             */
/*   Updated: 2021/06/02 15:31:05 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verif_defines(void)
{
	if (FOV < 0 || FOV > 360)
		ft_error("Impossible Field Of View (FOV)");
	if (G < 0 || G > 50)
		ft_error("Impossible gravity (G)");
	if (Z < 0.1 || Z > 0.9)
		ft_error("Impossible size/height (Z)");
	if (NB_THREADS != (int)NB_THREADS || NB_THREADS < 1 || NB_THREADS > 16)
		ft_error("Impossible number of threads");
	if (LIGHT < 0 || LIGHT > 3)
		ft_error("Impossible distance for player's light");
	if (DISTANCE_LIGHT < 0 || DISTANCE_LIGHT > 50)
		ft_error("Impossible area for light");
	if (LIGHT_MIN < 0 || LIGHT_MIN > 1)
		ft_error("Impossible ambient's light ratio");
	if (SPEED <= 0 || SPEED > 50)
		ft_error("Impossible speed");
	if (SCALE < 1 || SCALE != (int)SCALE || SCALE > 5)
		ft_error("Impossible scale");
}
