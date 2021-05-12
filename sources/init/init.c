/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:07:08 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/12 18:47:21 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_param *p)
{
	p->mlx = malloc(sizeof(t_mlx));
	if (!p->mlx)
		ft_error_free(p, "Malloc error - Mlx struct");
	p->free |= F_MLX;
	p->mlx->mlx_ptr = mlx_init();
	if (!p->mlx->mlx_ptr)
		ft_error_free(p, "Impossible to start Minilibx");
	p->free |= F_MLX_PTR;
	p->mlx->win_ptr = NULL;
	p->mlx->f = 0;
	p->mlx->c = 0;
	p->mlx->hook_alpha = 0;
	p->mlx->hook_buttons = 0;
	p->mlx->fps = 0;
	p->mlx->time = 0;
	init_strings_fps(p->mlx->strings_fps);
}

static void	init_win(t_param *p)
{
	p->win = malloc(sizeof(t_win));
	if (!p->win)
		ft_error_free(p, "Malloc error - Win struct");
	p->free |= F_WIN;
	p->win->w = 0;
	p->win->h = 0;
	p->win->w05 = 0;
	p->win->h05 = 0;
	p->win->fov_h = 2 * tan(FOV * M_PI / 360);
	p->win->fov_v = 0;
	p->win->r_fov_h = 0;
	p->win->r_fov_v = 0;
}

static void	init_map(t_param *p)
{
	p->map = malloc(sizeof(t_map));
	if (!p->map)
		ft_error_free(p, "Malloc error - Map struct");
	p->free |= F_MAP;
	p->map->w = 0;
	p->map->h = 0;
	p->map->b = 0;
	p->map->dir = C_N;
	p->map->map = NULL;
	p->map->p_n = NULL;
	p->map->p_s = NULL;
	p->map->p_e = NULL;
	p->map->p_w = NULL;
}

static void	init_newton(t_param *p)
{
	p->jump = malloc(sizeof(t_newton));
	if (!p->jump)
		ft_error_free(p, "Malloc error - Newton struct");
	p->free |= F_NEWTON;
	p->jump->jump = 0;
	p->jump->phi = 0;
	p->jump->theta = 0;
	p->jump->t = time(NULL);
	p->jump->v0 = 3;
}

void	init(t_param *p)
{
	init_mlx(p);
	init_win(p);
	init_map(p);
	init_newton(p);
	p->rays = NULL;
	p->rays_theta = NULL;
	p->fps = 0;
	p->parameters = 0;
	p->angle_h = 0;
	p->angle_v = 0;
	p->key_ceil = 0;
	p->ceil = 0;
	p->rad = M_PI / 180;
	init_trigo(p);
	// p->nb_sprites = 0;
}

void	verif_defines(void)// A modidfier et compléter
{
	if (FOV < 0 || FOV > 360)
		ft_error("Impossible Field Of View (FOV)");
	if (P_R != 1 || P_NO != 2 || P_SO != 4 || P_WE != 8 || P_EA != 16
		|| P_S != 32 || P_F != 64 || P_C != 128)
		ft_error("Enum t_parameters modified");
	if (F_MLX_PTR != 1 << 0 || F_MLX_WIN != 1 << 1 || F_MLX_IMG != 1 << 2 \
			|| F_MLX_NO != 1 << 3 || F_MLX_SO != 1 << 4 || F_MLX_WE != 1 << 5 \
			|| F_MLX_EA != 1 << 6 || F_MLX_S != 1 << 7 || F_MLX != 1 << 8 \
			|| F_WIN != 1 << 9 || F_MAP_MAP != 1 << 10 || F_MAP_PN != 1 << 11 \
			|| F_MAP_PS != 1 << 12 || F_MAP_PE != 1 << 13 \
			|| F_MAP_PW != 1 << 14 || F_MAP != 1 << 15 || F_RAYS != 1 << 16 \
			|| F_RAYS_THETA != 1 << 17 || F_SPRITES != 1 << 18 \
			|| F_NEWTON != 1 << 19 || F_CLOSE != 1 << 20)
		ft_error("Enum t_free modified");
}
