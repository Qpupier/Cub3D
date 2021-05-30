/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:58:56 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 16:59:59 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verif_defines(void)// A modidfier et compléter
{
	if (FOV < 0 || FOV > 360)
		ft_error("Impossible Field Of View (FOV)");
	if (P_R != 1 << 0 || P_NO != 1 << 1 || P_SO != 1 << 2 || P_WE != 1 << 3 \
			|| P_EA != 1 << 4 || P_F != 1 << 5 || P_C != 1 << 6 \
			|| P_S != 1 << 7)
		ft_error("Enum t_parameters modified");
	if (F_MLX_PTR != 1 << 0 || F_MLX_WIN != 1 << 1 || F_MLX_IMG != 1 << 2 \
			|| F_MLX_SPRITE != 1 << 3 || F_MLX_NO != 1 << 4 \
			|| F_MLX_SO != 1 << 5 || F_MLX_WE != 1 << 6 || F_MLX_EA != 1 << 7 \
			|| F_MLX_F != 1 << 8 || F_MLX_C != 1 << 9 || F_MLX != 1 << 10 \
			|| F_WIN != 1 << 11 || F_MAP_SPRITES != 1 << 12 \
			|| F_MAP_MAP != 1 << 13 || F_MAP_PN != 1 << 14 \
			|| F_MAP_PS != 1 << 15 || F_MAP_PE != 1 << 16 \
			|| F_MAP_PW != 1 << 17 || F_MAP != 1 << 18 || F_RAYS != 1 << 19 \
			|| F_RAYS_THETA != 1 << 20 || F_NEWTON != 1 << 21 \
			|| F_CLOSE != 1 << 22)
		ft_error("Enum t_free modified");
}
