/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:17:00 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/26 19:08:32 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_trigo(t_param *p)
{
	t_vec	move[4];
	t_vec	newton;
	int		i;

	move[0] = (t_vec){0, -0.3, 0};
	move[1] = (t_vec){-0.3, 0, 0};
	move[2] = (t_vec){0, 0.3, 0};
	move[3] = (t_vec){0.3, 0, 0};
	newton = (t_vec){1, 0, 0};
	i = -1;
	while (++i < 360)
	{
		p->trigo_cos[i] = cos(i * p->rad);
		p->trigo_sin[i] = sin(i * p->rad);
		p->pre_move[0][i] = vec_rot_z_pre(p, move[0], i);
		p->pre_move[1][i] = vec_rot_z_pre(p, move[1], i);
		p->pre_move[2][i] = vec_rot_z_pre(p, move[2], i);
		p->pre_move[3][i] = vec_rot_z_pre(p, move[3], i);
		p->pre_move[4][i] = vec_rot_z_pre(p, newton, i);
	}
}

void	init_rays_theta(t_param *p)
{
	int	theta;
	int	i;

	p->rays_theta = malloc(sizeof(t_vec *) * 360);
	theta = -1;
	if (!p->rays_theta)
		ft_error_free_array(p, theta, "Malloc error - Init rays_theta");
	while (++theta < 360)
	{
		p->rays_theta[theta] = malloc(sizeof(t_vec) * p->win->w * p->win->h);
		if (!p->rays_theta[theta])
			ft_error_free_array(p, theta, "Malloc error - Init rays_theta");
		i = -1;
		while (++i < p->win->w * p->win->h)
			p->rays_theta[theta][i] = vec_rot_x_pre(p, p->rays[i], theta);
	}
	p->free |= F_RAYS_THETA;
	printf("OK\n");
}
