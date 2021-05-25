/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:40:51 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/25 18:14:13 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	jump(t_param *p)
{
	p->jump->jump = 1;
	p->jump->p0 = p->map->player;
	p->jump->t = 0;
	p->jump->phi = 0;
	p->jump->theta = 0;
}

void	jump_w(t_param *p)
{
	p->jump->jump = 1;
	p->jump->p0 = p->map->player;
	p->jump->t = 0;
	p->jump->phi = p->angle_h - 90;
	if (p->jump->phi < 0)
		p->jump->phi += 360;
	p->jump->theta = 65;
	p->jump->v0 = 4;
}

void	jump_a(t_param *p)
{
	p->jump->jump = 1;
	p->jump->p0 = p->map->player;
	p->jump->t = 0;
	p->jump->phi = p->angle_h + 180;
	if (p->jump->phi >= 360)
		p->jump->phi -= 360;
	p->jump->theta = 65;
	p->jump->v0 = 4;
}

void	jump_s(t_param *p)
{
	p->jump->jump = 1;
	p->jump->p0 = p->map->player;
	p->jump->t = 0;
	p->jump->phi = p->angle_h + 90;
	if (p->jump->phi >= 360)
		p->jump->phi -= 360;
	p->jump->theta = 65;
	p->jump->v0 = 4;
}

void	jump_d(t_param *p)
{
	p->jump->jump = 1;
	p->jump->p0 = p->map->player;
	p->jump->t = 0;
	p->jump->phi = p->angle_h;
	p->jump->theta = 65;
	p->jump->v0 = 4;
}

void	events(t_param *p)
{
	if (p->mlx->hook_buttons & H_ESC)
		win_exit(p);
	if (p->mlx->hook_buttons & H_LEFT)
	{
		p->angle_h -= 5;
		if (p->angle_h < 0)
			p->angle_h += 360;
	}
	if (p->mlx->hook_buttons & H_RIGHT)
	{
		p->angle_h += 5;
		if (p->angle_h >= 360)
			p->angle_h -= 360;
	}
	if (p->mlx->hook_buttons & H_UP)
	{
		p->angle_v -= 3;
		if (p->angle_v < 0)
			p->angle_v += 360;
	}
	if (p->mlx->hook_buttons & H_DOWN)
	{
		p->angle_v += 3;
		if (p->angle_v >= 360)
			p->angle_v -= 360;
	}
	if (p->mlx->hook_alpha & H_R)
		p->map->player.z += 0.3;//A LIMITER
	if (p->mlx->hook_alpha & H_F)
		p->map->player.z -= 0.3;//A LIMITER
	if (!(p->mlx->hook_buttons & H_SPACE))
	{
		if (p->mlx->hook_alpha & H_W)
			p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){0, -0.3, 0}, p->angle_h * M_PI / 180));//PRECALCULER
		if (p->mlx->hook_alpha & H_S)
			p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){0, 0.3, 0}, p->angle_h * M_PI / 180));//PRECALCULER
		if (p->mlx->hook_alpha & H_A)
			p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){-0.3, 0, 0}, p->angle_h * M_PI / 180));//PRECALCULER
		if (p->mlx->hook_alpha & H_D)
			p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){0.3, 0, 0}, p->angle_h * M_PI / 180));//PRECALCULER
	}
	else if (!p->jump->jump)
	{
		if (p->mlx->hook_alpha & H_W)
			jump_w(p);
		else if (p->mlx->hook_alpha & H_A)
			jump_a(p);
		else if (p->mlx->hook_alpha & H_S)
			jump_s(p);
		else if (p->mlx->hook_alpha & H_D)
			jump_d(p);
		else
			jump(p);
	}
	if (p->mlx->hook_alpha & H_C)
	{
		if (!p->key_ceil)
			p->ceil = !p->ceil;
		p->key_ceil = 1;
	}
	else
		p->key_ceil = 0;
	if (p->jump->jump)
		ft_newton(p);
}
