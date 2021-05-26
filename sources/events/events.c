/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:40:51 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/26 20:18:17 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	collisions(t_param *p, t_vec vec)
{
	int	out_x;
	int	out_y;
	int	move_x;
	int	move_y;
	int	move_xy;

	out_x = vec.x < 0 || vec.x >= p->map->w;
	out_y = vec.y < 0 || vec.y >= p->map->h;
	move_x = out_x || p->map->player.y < 0 || p->map->player.y >= p->map->h \
			|| !p->map->map[(int)p->map->player.y][(int)vec.x];
	move_y = out_y || p->map->player.x < 0 || p->map->player.x >= p->map->w \
			|| !p->map->map[(int)vec.y][(int)p->map->player.x];
	move_xy = (move_x || move_y) && (out_x || out_y \
			|| !p->map->map[(int)vec.y][(int)vec.x]);
	if (p->map->player.z > 1 || move_xy)
		p->map->player = vec;
	else if (!move_x || !move_y)
	{
		if (move_x)
			p->map->player.x = vec.x;
		else if (move_y)
			p->map->player.y = vec.y;
	}
}

void	events(t_param *p)
{
	t_move_buttons	card;
	t_vec			vec;

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
	if (p->mlx->hook_alpha & H_R && p->map->player.z + 0.3 < MAXFLOAT)
		p->map->player.z += 0.3;
	if (p->mlx->hook_alpha & H_F && p->map->player.z - 0.3 < 1 - MAXFLOAT)
		p->map->player.z -= 0.3;
	if (!p->jump->jump)
	{
		if (!(p->mlx->hook_buttons & H_SPACE))
		{
			if (!(p->mlx->hook_buttons & H_SHIFT))
			{
				vec = (t_vec){0, 0, 0};
				if (p->mlx->hook_alpha & H_W)
					vec = vec_add(vec, p->pre_move[0][p->angle_h]);
				if (p->mlx->hook_alpha & H_A)
					vec = vec_add(vec, p->pre_move[1][p->angle_h]);
				if (p->mlx->hook_alpha & H_S)
					vec = vec_add(vec, p->pre_move[2][p->angle_h]);
				if (p->mlx->hook_alpha & H_D)
					vec = vec_add(vec, p->pre_move[3][p->angle_h]);
				collisions(p, vec_add(p->map->player, vec));
				if (p->gravity && p->map->player.z > Z)
				{
					p->jump->jump = 1;
					p->jump->p0 = p->map->player;
					p->jump->t = 0;
					p->jump->phi = 0;
					p->jump->theta = 0;
					p->jump->v0 = 0;
				}
			}
			else
			{
				card = 0;
				if (p->mlx->hook_alpha & H_W)
					card += M_W;
				if (p->mlx->hook_alpha & H_A)
					card += M_A;
				if (p->mlx->hook_alpha & H_S)
					card += M_S;
				if (p->mlx->hook_alpha & H_D)
					card += M_D;
				move(p, card);
			}
		}
		else if (!(p->mlx->hook_buttons & H_SHIFT))
		{
			card = 0;
			if (p->mlx->hook_alpha & H_W)
				card += M_W;
			if (p->mlx->hook_alpha & H_A)
				card += M_A;
			if (p->mlx->hook_alpha & H_S)
				card += M_S;
			if (p->mlx->hook_alpha & H_D)
				card += M_D;
			jump(p, card);
		}
	}
	if (p->mlx->hook_alpha & H_C)
	{
		if (!p->key_ceil)
			p->ceil = !p->ceil;
		p->key_ceil = 1;
	}
	else
		p->key_ceil = 0;
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
}
