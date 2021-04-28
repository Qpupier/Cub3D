/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:40:51 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/28 15:49:13 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	events(t_param *p)
{
	if (p->mlx->hook & H_ESC)
		win_exit(p);
	if (p->mlx->hook & H_LEFT)
		p->angle_h -= 0.1;
	if (p->mlx->hook & H_RIGHT)
		p->angle_h += 0.1;
	if (p->mlx->hook & H_UP)
		p->angle_v -= 0.05;
	if (p->mlx->hook & H_DOWN)
		p->angle_v += 0.05;
	if (p->mlx->hook & H_W)
		p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){0, -0.3, 0}, p->angle_h));//PRECALCULER
	if (p->mlx->hook & H_S)
		p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){0, 0.3, 0}, p->angle_h));//PRECALCULER
	if (p->mlx->hook & H_A)
		p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){-0.3, 0, 0}, p->angle_h));//PRECALCULER
	if (p->mlx->hook & H_D)
		p->map->player = vec_add(p->map->player, vec_rot_z((t_vec){0.3, 0, 0}, p->angle_h));//PRECALCULER
	if (p->mlx->hook & H_R)
		p->map->player.z += 0.3;
	if (p->mlx->hook & H_F)
		p->map->player.z -= 0.3;
}
