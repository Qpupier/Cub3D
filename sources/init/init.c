/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:07:08 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 19:39:37 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_param *p)
{
	int	i;

	p->mlx = malloc(sizeof(t_mlx));
	if (!p->mlx)
		ft_error_free(p, "Malloc error - Mlx struct");
	p->free |= F_MLX;
	p->mlx->mlx_ptr = mlx_init();
	if (!p->mlx->mlx_ptr)
		ft_error_free(p, "Impossible to start Minilibx");
	p->free |= F_MLX_PTR;
	p->mlx->win_ptr = NULL;
	p->mlx->sprite.wall = 0;
	p->mlx->sprite.color = 0;
	i = -1;
	while (++i < 6)
	{
		p->mlx->walls[i].wall = 0;
		p->mlx->walls[i].color = 0;
	}
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
	p->win->h = 0;
	p->win->h_scale = 0;
	p->win->w = 0;
	p->win->w_scale = 0;
	p->win->h05 = 0;
	p->win->w05 = 0;
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
	p->map->dir = C_N;
	p->map->sprites = NULL;
	p->map->map = NULL;
	p->map->p_e = NULL;
	p->map->p_n = NULL;
	p->map->p_s = NULL;
	p->map->p_w = NULL;
	p->map->b = 0;
	p->map->h = 0;
	p->map->nb_sprites = 0;
	p->map->w = 0;
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
	p->gravity = 1;
	p->parameters = 0;
	p->angle_h = 0;
	p->angle_v = 0;
	p->key_ceil = 0;
	p->ceil = 0;
	p->rad = M_PI / 180;
	init_trigo(p);
}
