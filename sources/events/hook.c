/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:41:02 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/20 13:26:50 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_quater(t_key key, t_param *p)
{
	if (key == K_CMD)
		p->mlx->hook |= H_CMD;
	else if (key == K_ALT)
		p->mlx->hook |= H_ALT;
	return (0);
}

static int	key_press_ter(t_key key, t_param *p)
{
	if (key == K_W)
		p->mlx->hook |= H_W;
	else if (key == K_X)
		p->mlx->hook |= H_X;
	else if (key == K_Y)
		p->mlx->hook |= H_Y;
	else if (key == K_Z)
		p->mlx->hook |= H_Z;
	else if (key == K_ESC)
		p->mlx->hook |= H_ESC;
	else if (key == K_LEFT)
		p->mlx->hook |= H_LEFT;
	else if (key == K_RIGHT)
		p->mlx->hook |= H_RIGHT;
	else if (key == K_DOWN)
		p->mlx->hook |= H_DOWN;
	else if (key == K_UP)
		p->mlx->hook |= H_UP;
	else if (key == K_CTRL)
		p->mlx->hook |= H_CTRL;
	else if (key == K_SHIFT)
		p->mlx->hook |= H_SHIFT;
	else
		return (key_press_quater(key, p));
	return (0);
}

static int	key_press_bis(t_key key, t_param *p)
{
	if (key == K_L)
		p->mlx->hook |= H_L;
	else if (key == K_M)
		p->mlx->hook |= H_M;
	else if (key == K_N)
		p->mlx->hook |= H_N;
	else if (key == K_O)
		p->mlx->hook |= H_O;
	else if (key == K_P)
		p->mlx->hook |= H_P;
	else if (key == K_Q)
		p->mlx->hook |= H_Q;
	else if (key == K_R)
		p->mlx->hook |= H_R;
	else if (key == K_S)
		p->mlx->hook |= H_S;
	else if (key == K_T)
		p->mlx->hook |= H_T;
	else if (key == K_U)
		p->mlx->hook |= H_U;
	else if (key == K_V)
		p->mlx->hook |= H_V;
	else
		return (key_press_ter(key, p));
	return (0);
}

int	key_press(int key, t_param *p)
{
	if (key == K_A)
		p->mlx->hook |= H_A;
	else if (key == K_B)
		p->mlx->hook |= H_B;
	else if (key == K_C)
		p->mlx->hook |= H_C;
	else if (key == K_D)
		p->mlx->hook |= H_D;
	else if (key == K_E)
		p->mlx->hook |= H_E;
	else if (key == K_F)
		p->mlx->hook |= H_F;
	else if (key == K_G)
		p->mlx->hook |= H_G;
	else if (key == K_H)
		p->mlx->hook |= H_H;
	else if (key == K_I)
		p->mlx->hook |= H_I;
	else if (key == K_J)
		p->mlx->hook |= H_J;
	else if (key == K_K)
		p->mlx->hook |= H_K;
	else
		return (key_press_bis(key, p));
	return (0);
}

int	win_exit(t_param *p)
{
	free_all(p);
	exit(0);
	return (0);
}
