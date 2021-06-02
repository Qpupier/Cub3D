/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:40:51 by qpupier           #+#    #+#             */
/*   Updated: 2021/06/02 15:15:28 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_gravity(t_param *p)
{
	p->jump->jump = 1;
	p->jump->p0 = p->map->player;
	p->jump->t = 0;
	p->jump->phi = 0;
	p->jump->theta = 0;
	p->jump->v0 = 0;
}

static void	events_rotations(t_param *p)
{
	short	tp;

	if (p->mlx->hook_buttons & H_LEFT)
	{
		p->angle_h -= SPEED * 20;
		if (p->angle_h < 0)
			p->angle_h += 360;
	}
	if (p->mlx->hook_buttons & H_RIGHT)
	{
		p->angle_h += SPEED * 20;
		if (p->angle_h >= 360)
			p->angle_h -= 360;
	}
	tp = p->angle_v;
	if (p->mlx->hook_buttons & H_UP)
		tp -= SPEED * 15;
	if (p->mlx->hook_buttons & H_DOWN)
		tp += SPEED * 15;
	if (tp < 0)
		tp += 360;
	if (tp >= 360)
		tp -= 360;
	if (p->map->player.z < 0 || p->map->player.z >= 1 || tp <= 60 || tp >= 300)
		p->angle_v = tp;
}

static void	events_gravity(t_param *p)
{
	if (p->mlx->hook_alpha & H_G)
	{
		if (!p->key_gravity)
			p->gravity = !p->gravity;
		p->key_gravity = 1;
	}
	else
		p->key_gravity = 0;
	if (p->jump->jump)
		ft_newton(p);
	else if (p->gravity && p->map->player.z > Z)
		set_gravity(p);
}

void	events(t_param *p)
{
	if (p->mlx->hook_buttons & H_ESC)
		win_exit(p);
	events_rotations(p);
	if (p->mlx->hook_alpha & H_R && p->map->player.z + SPEED < MAXFLOAT)
		p->map->player.z += SPEED;
	if (p->mlx->hook_alpha & H_F && p->map->player.z - SPEED < 1 - MAXFLOAT)
		p->map->player.z -= SPEED;
	if (!p->jump->jump)
		events_move(p);
	if (p->mlx->hook_alpha & H_C)
	{
		if (!p->key_ceil)
			p->ceil = !p->ceil;
		p->key_ceil = 1;
	}
	else
		p->key_ceil = 0;
	events_gravity(p);
}
