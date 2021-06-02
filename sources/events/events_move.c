/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:06:57 by qpupier           #+#    #+#             */
/*   Updated: 2021/06/02 15:08:45 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	collisions(t_param *p, t_vec vec)
{
	int	out_x;
	int	out_y;
	int	move_x;
	int	move_y;
	int	move_xy;

	out_x = vec.x < 0 || vec.x >= p->map->w;
	out_y = vec.y < 0 || vec.y >= p->map->h;
	move_x = out_x || p->map->player.y < 0 || p->map->player.y >= p->map->h \
			|| p->map->map[(int)p->map->player.y][(int)vec.x] != 1;
	move_y = out_y || p->map->player.x < 0 || p->map->player.x >= p->map->w \
			|| p->map->map[(int)vec.y][(int)p->map->player.x] != 1;
	move_xy = (move_x || move_y) && (out_x || out_y \
			|| p->map->map[(int)vec.y][(int)vec.x] != 1);
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

static void	events_move_shift(t_param *p)
{
	t_vec	vec;

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
}

static void	events_move_default(t_param *p)
{
	t_move_buttons	card;

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

void	events_move(t_param *p)
{
	t_move_buttons	card;

	if (!(p->mlx->hook_buttons & H_SPACE))
	{
		if (!(p->mlx->hook_buttons & H_SHIFT))
			events_move_shift(p);
		else
			events_move_default(p);
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
