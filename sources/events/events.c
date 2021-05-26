/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:40:51 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/26 11:56:53 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	events(t_param *p)
{
	t_move_buttons card;

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
		if (p->mlx->hook_buttons & H_SHIFT)
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
	else if (!(p->mlx->hook_buttons & H_SHIFT || p->jump->jump))
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
