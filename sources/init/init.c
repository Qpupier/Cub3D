/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:07:08 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/28 18:59:04 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_param *p)
{
	p->mlx->mlx_ptr = mlx_init();
	if (!p->mlx->mlx_ptr)
		ft_error_free(p, "Impossible to start Minilibx");
	p->free |= F_MLX_PTR;
	p->mlx->hook = 0;
	p->mlx->time = 0;
	p->mlx->fps = 0;
	init_strings_fps(p->mlx->strings_fps);
}

void	init(t_param *p)
{
	p->mlx = malloc(sizeof(t_mlx));
	if (!p->mlx)
		ft_error_free(p, "Malloc error - Mlx struct");
	p->free |= F_MLX;
	init_mlx(p);
	p->win = malloc(sizeof(t_win));
	if (!p->win)
		ft_error_free(p, "Malloc error - Win struct");
	p->free |= F_WIN;
	p->win->fov_h = FOV * M_PI / 180;
	p->win->fov_h = 2 * tan(p->win->fov_h * 0.5);
	p->map = malloc(sizeof(t_map));
	if (!p->map)
		ft_error_free(p, "Malloc error - Map struct");
	p->free |= F_MAP;
	p->map->w = 0;
	p->angle_h = 0;
	p->angle_v = 0;
	p->parameters = 0;
	// p->nb_sprites = 0;
	p->fps = 0;
}

void	verif_defines(void)// A modidfier et compléter
{
	if (FOV < 0 || FOV > 360)
		ft_error("Impossible Field Of View (FOV)");
	if (P_R != 1 || P_NO != 2 || P_SO != 4 || P_WE != 8 || P_EA != 16
		|| P_S != 32 || P_F != 64 || P_C != 128)
		ft_error("Enum t_parameters modified");
	if (F_MLX_PTR != 1 || F_MLX_WIN != 2 || F_MLX_IMG != 4
		|| F_MLX_NO != 8 || F_MLX_SO != 16 || F_MLX_WE != 32
		|| F_MLX_EA != 64 || F_MLX_S != 128 || F_MLX != 256
		|| F_WIN != 512 || F_MAP_MAP != 1024 || F_MAP_PN != 2048
		|| F_MAP_PS != 4096 || F_MAP_PE != 8192 || F_MAP_PW != 16384
		|| F_MAP != 32768 || F_RAYS != 65536 || F_SPRITES != 131072
		|| F_CLOSE != 262144)
		ft_error("Enum t_free modified");
}
