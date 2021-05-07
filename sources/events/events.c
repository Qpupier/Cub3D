/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:40:51 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/07 13:57:19 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test(t_param *p)
{
	// unsigned short int	t;
	t_vec				vec;
	t_vec				tmp;
	float				prec1;
	float				prec2;

	if (!p->jump->jump)
	{
		p->jump->jump = 1;
		p->jump->p0 = p->map->player;
		// p->jump->t = time(NULL);
		p->jump->t = 0;
	}
	// t = time(NULL) - p->jump->t;
	p->jump->t += 0.03;
	// p->jump->theta = 40;
	prec1 = p->jump->v0 * p->jump->t;
	prec2 = p->trigo_sin[p->jump->theta] * prec1;
	vec.x = p->trigo_cos[p->jump->phi] * prec2;
	vec.y = p->trigo_sin[p->jump->phi] * prec2;
	vec.z = -G * p->jump->t * p->jump->t * 0.5 + p->trigo_cos[p->jump->theta] * prec1;
	// if (p->jump->jump)
		// printf("%f\n", vec.z);
	tmp = vec_add(p->jump->p0, vec);
	if (tmp.z >= 0.5)
		p->map->player = tmp;
	else
	{
		p->map->player.z = 0.5;
		p->jump->jump = 0;
	}
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
	if (p->mlx->hook_alpha & H_W)
		p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){0, -0.3, 0}, p->angle_h * M_PI / 180));//PRECALCULER
	if (p->mlx->hook_alpha & H_S)
		p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){0, 0.3, 0}, p->angle_h * M_PI / 180));//PRECALCULER
	if (p->mlx->hook_alpha & H_A)
		p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){-0.3, 0, 0}, p->angle_h * M_PI / 180));//PRECALCULER
	if (p->mlx->hook_alpha & H_D)
		p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){0.3, 0, 0}, p->angle_h * M_PI / 180));//PRECALCULER
	if (p->mlx->hook_alpha & H_R)
		p->map->player.z += 0.3;//A LIMITER
	if (p->mlx->hook_alpha & H_F)
		p->map->player.z -= 0.3;//A LIMITER
	if (p->mlx->hook_buttons & H_SPACE)
		test(p);
}
