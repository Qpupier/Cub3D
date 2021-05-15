/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:40:51 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/15 16:31:00 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test(t_param *p)
{
	if (!p->jump->jump)
	{
		p->jump->jump = 1;
		p->jump->p0 = p->map->player;
		p->jump->t = 0;
		p->jump->phi = 15;
		p->jump->theta = 60;
	}
}

void	equation_y(t_param *p, float *y1, float *y2)
{
	float	cos_theta;
	float	sin_theta;
	float	sin_phi;
	float	A;
	float	B;
	float	C;
	float	D;
	float	a;
	float	b;
	float	c;
	float	delta;

	cos_theta = p->trigo_cos[p->jump->theta];
	sin_theta = p->trigo_sin[p->jump->theta];
	sin_phi = p->trigo_sin[p->jump->phi];
	A = 2 * p->jump->v0 * p->jump->v0 * sin_phi * sin_phi * sin_theta * sin_theta;
	B = sin_phi * sin_theta;
	C = G / A;
	D = cos_theta / B;
	a = -C;
	b = 2 * p->jump->p0.y * C + D;
	c = p->jump->p0.z - Z - p->jump->p0.y * (p->jump->p0.y * C + D);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return ;
	*y1 = (-b - sqrt(delta)) / (2 * a);
	*y2 = (-b + sqrt(delta)) / (2 * a);
	// printf("%f\n%f\n\n", *x1, *x2);
}

void	equation_x(t_param *p, float *x1, float *x2)
{
	float	cos_phi;
	float	cos_theta;
	float	sin_theta;
	float	A;
	float	B;
	float	C;
	float	D;
	float	a;
	float	b;
	float	c;
	float	delta;

	cos_phi = p->trigo_cos[p->jump->phi];
	cos_theta = p->trigo_cos[p->jump->theta];
	sin_theta = p->trigo_sin[p->jump->theta];
	A = 2 * p->jump->v0 * p->jump->v0 * cos_phi * cos_phi * sin_theta * sin_theta;
	B = cos_phi * sin_theta;
	C = G / A;
	D = cos_theta / B;
	a = -C;
	b = 2 * p->jump->p0.x * C + D;
	c = p->jump->p0.z - Z - p->jump->p0.x * (p->jump->p0.x * C + D);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return ;
	*x1 = (-b - sqrt(delta)) / (2 * a);
	*x2 = (-b + sqrt(delta)) / (2 * a);
}

t_vec	choice_equation_point(t_param *p, float x1, float x2, float y1, float y2)
{
	t_vec	orig;
	t_vec	pot[4];
	float	v[4];
	float	result;
	t_vec	point;
	int		i;

	orig = vec_rot_z((t_vec){1, 0, 0}, p->jump->phi * M_PI / 180);
	pot[0] = (t_vec){x1, y1, Z};
	pot[1] = (t_vec){x1, y2, Z};
	pot[2] = (t_vec){x2, y1, Z};
	pot[3] = (t_vec){x2, y2, Z};
	result = -1;
	point = pot[0];
	i = -1;
	while (++i < 4)
	{
		v[i] = vec_scale_product(orig, vec_sub(pot[i], p->map->player));
		if (v[i] > result)
		{
			result = v[i];
			point = pot[i];
		}
	}
	return (point);
}

t_vec	equation(t_param *p)
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;

	equation_x(p, &x1, &x2);
	equation_y(p, &y1, &y2);
	return (choice_equation_point(p, x1, x2, y1, y2));
}

void	ft_newton(t_param *p)
{
	t_vec				vec;
	t_vec				tmp;
	float				prec1;
	float				prec2;

	p->jump->t += 1.0 / p->fps;
	prec1 = p->jump->v0 * p->jump->t;
	prec2 = p->trigo_sin[p->jump->theta] * prec1;
	vec.x = p->trigo_cos[p->jump->phi] * prec2;
	vec.y = p->trigo_sin[p->jump->phi] * prec2;
	vec.z = -G * p->jump->t * p->jump->t * 0.5 + p->trigo_cos[p->jump->theta] * prec1;
	tmp = vec_add(p->jump->p0, vec);
	if (tmp.z >= Z)
		p->map->player = tmp;
	else
	{
		p->map->player = equation(p);
		// p->map->player.z = Z;
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
