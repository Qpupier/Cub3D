/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:41:02 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/06 14:30:23 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_quater(t_key key, t_param *p)
{
	if (key == K_SHIFT)
		p->mlx->hook_buttons |= H_SHIFT;
	else if (key == K_CMD)
		p->mlx->hook_buttons |= H_CMD;
	else if (key == K_ALT)
		p->mlx->hook_buttons |= H_ALT;
	return (0);
}

static int	key_press_ter(t_key key, t_param *p)
{
	if (key == K_W)
		p->mlx->hook_alpha |= H_W;
	else if (key == K_X)
		p->mlx->hook_alpha |= H_X;
	else if (key == K_Y)
		p->mlx->hook_alpha |= H_Y;
	else if (key == K_Z)
		p->mlx->hook_alpha |= H_Z;
	else if (key == K_SPACE)
		p->mlx->hook_buttons |= H_SPACE;
	else if (key == K_ESC)
		p->mlx->hook_buttons |= H_ESC;
	else if (key == K_LEFT)
		p->mlx->hook_buttons |= H_LEFT;
	else if (key == K_RIGHT)
		p->mlx->hook_buttons |= H_RIGHT;
	else if (key == K_DOWN)
		p->mlx->hook_buttons |= H_DOWN;
	else if (key == K_UP)
		p->mlx->hook_buttons |= H_UP;
	else if (key == K_CTRL)
		p->mlx->hook_buttons |= H_CTRL;
	else
		return (key_press_quater(key, p));
	return (0);
}

static int	key_press_bis(t_key key, t_param *p)
{
	if (key == K_L)
		p->mlx->hook_alpha |= H_L;
	else if (key == K_M)
		p->mlx->hook_alpha |= H_M;
	else if (key == K_N)
		p->mlx->hook_alpha |= H_N;
	else if (key == K_O)
		p->mlx->hook_alpha |= H_O;
	else if (key == K_P)
		p->mlx->hook_alpha |= H_P;
	else if (key == K_Q)
		p->mlx->hook_alpha |= H_Q;
	else if (key == K_R)
		p->mlx->hook_alpha |= H_R;
	else if (key == K_S)
		p->mlx->hook_alpha |= H_S;
	else if (key == K_T)
		p->mlx->hook_alpha |= H_T;
	else if (key == K_U)
		p->mlx->hook_alpha |= H_U;
	else if (key == K_V)
		p->mlx->hook_alpha |= H_V;
	else
		return (key_press_ter(key, p));
	return (0);
}

int	key_press(int key, t_param *p)
{
	if (key == K_A)
		p->mlx->hook_alpha |= H_A;
	else if (key == K_B)
		p->mlx->hook_alpha |= H_B;
	else if (key == K_C)
		p->mlx->hook_alpha |= H_C;
	else if (key == K_D)
		p->mlx->hook_alpha |= H_D;
	else if (key == K_E)
		p->mlx->hook_alpha |= H_E;
	else if (key == K_F)
		p->mlx->hook_alpha |= H_F;
	else if (key == K_G)
		p->mlx->hook_alpha |= H_G;
	else if (key == K_H)
		p->mlx->hook_alpha |= H_H;
	else if (key == K_I)
		p->mlx->hook_alpha |= H_I;
	else if (key == K_J)
		p->mlx->hook_alpha |= H_J;
	else if (key == K_K)
		p->mlx->hook_alpha |= H_K;
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
