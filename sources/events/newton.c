/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:22:26 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/25 18:20:11 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	equation_x(t_param *p, float *x1, float *x2)
{
	float	a;
	float	b;
	float	c;
	float	delta;
	float	prec[8];

	prec[0] = p->trigo_cos[p->jump->phi];
	prec[1] = p->trigo_sin[p->jump->theta];
	prec[2] = prec[0] * prec[1];
	prec[3] = 2 * p->jump->v0 * p->jump->v0 * prec[0] * prec[1] * prec[2];
	if (!prec[2] || !prec[3])
		return ;
	prec[3] = G / prec[3];
	prec[4] = p->trigo_cos[p->jump->theta] / prec[2];
	prec[5] = p->jump->p0.x * prec[3];
	a = -prec[3];
	b = 2 * prec[5] + prec[4];
	c = p->jump->p0.z - Z - p->jump->p0.x * (prec[4] + prec[5]);
	delta = b * b - 4 * a * c;
	if (delta < 0 || !a)
		return ;
	prec[6] = sqrt(delta);
	prec[7] = 1 / (2 * a);
	*x1 = (-b - prec[6]) * prec[7];
	*x2 = (-b + prec[6]) * prec[7];
}

static void	equation_y(t_param *p, float *y1, float *y2)
{
	float	a;
	float	b;
	float	c;
	float	delta;
	float	prec[8];

	prec[0] = p->trigo_sin[p->jump->phi];
	prec[1] = p->trigo_sin[p->jump->theta];
	prec[2] = prec[0] * prec[1];
	prec[3] = 2 * p->jump->v0 * p->jump->v0 * prec[0] * prec[1] * prec[2];
	if (!prec[2] || !prec[3])
		return ;
	prec[3] = G / prec[3];
	prec[4] = p->trigo_cos[p->jump->theta] / prec[2];
	prec[5] = p->jump->p0.y * prec[3];
	a = -prec[3];
	b = 2 * prec[5] + prec[4];
	c = p->jump->p0.z - Z - p->jump->p0.y * (prec[4] + prec[5]);
	delta = b * b - 4 * a * c;
	if (delta < 0 || !a)
		return ;
	prec[6] = sqrt(delta);
	prec[7] = 1 / (2 * a);
	*y1 = (-b - prec[6]) * prec[7];
	*y2 = (-b + prec[6]) * prec[7];
}

static t_vec	choice_equation_point(t_param *p, t_vec ext1, t_vec ext2, \
		float	*result)
{
	t_vec	potential[4];
	t_vec	orig;
	t_vec	point;
	int		i;
	float	v[4];

	orig = vec_rot_z((t_vec){1, 0, 0}, p->jump->phi * M_PI / 180);//A MODIFIER avec les avancements
	potential[0] = (t_vec){ext1.x, ext1.y, Z};
	potential[1] = (t_vec){ext1.x, ext2.y, Z};
	potential[2] = (t_vec){ext2.x, ext1.y, Z};
	potential[3] = (t_vec){ext2.x, ext2.y, Z};
	*result = -1;
	point = potential[0];
	i = -1;
	while (++i < 4)
	{
		v[i] = vec_scale_product(orig, vec_sub(potential[i], p->map->player));
		if (v[i] > *result)
		{
			*result = v[i];
			point = potential[i];
		}
	}
	return (point);
}

static t_vec	equation(t_param *p)
{
	t_vec	ext1;
	t_vec	ext2;
	float	result;

	ext1 = (t_vec){p->jump->p0.x, p->jump->p0.y, Z};
	ext2 = (t_vec){p->jump->p0.x, p->jump->p0.y, Z};
	// printf("%f, %f | %f, %f\n", ext1.x, ext1.y, ext2.x, ext2.y);
	equation_x(p, &ext1.x, &ext2.x);
	equation_y(p, &ext1.y, &ext2.y);
	// printf("%f, %f | %f, %f\n\n", ext1.x, ext1.y, ext2.x, ext2.y);
	return (choice_equation_point(p, ext1, ext2, &result));
}

void	ft_newton(t_param *p)
{
	t_vec	tmp;
	t_vec	vec;
	float	prec1;
	float	prec2;

	if (p->fps)
		p->jump->t += 1. / p->fps;
	prec1 = p->jump->v0 * p->jump->t;
	prec2 = p->trigo_sin[p->jump->theta] * prec1;
	vec.x = p->trigo_cos[p->jump->phi] * prec2;
	vec.y = p->trigo_sin[p->jump->phi] * prec2;
	vec.z = -G * p->jump->t * p->jump->t * 0.5 + \
			p->trigo_cos[p->jump->theta] * prec1;
	tmp = vec_add(p->jump->p0, vec);
	if (tmp.z >= Z)
		p->map->player = tmp;
	else
	{
		p->jump->jump = 0;
		p->map->player = equation(p);
	}
}
