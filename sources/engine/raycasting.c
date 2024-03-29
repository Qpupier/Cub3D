/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:03:09 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/31 16:04:51 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_card(t_param *p, t_inter check[], t_vec ray, \
		unsigned int *pixel)
{
	float	dis;
	int		card;
	int		i;

	dis = -1;
	card = -1;
	i = -1;
	while (++i < 6)
	{
		if (check[i].t > 0 && (dis < 0 || check[i].t <= dis))
		{
			dis = check[i].t;
			card = i;
		}
	}
	check[6].t = check_sprites(p, dis, ray, pixel);
	if (check[6].t != -1)
		return (6);
	return (card);
}

static unsigned int	average_color(unsigned int color, float t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
	float			ratio;

	ratio = (t - LIGHT) / DISTANCE_LIGHT;
	if (ratio < 0)
		ratio = 0;
	if (ratio > 1)
		ratio = 1;
	ratio = 1 - ratio;
	if (ratio < LIGHT_MIN)
		ratio = LIGHT_MIN;
	a = (unsigned char)(color >> 24) *ratio;
	r = (unsigned char)(color >> 16) *ratio;
	g = (unsigned char)(color >> 8) *ratio;
	b = (unsigned char)(color) *ratio;
	return ((a << 24) + (r << 16) + (g << 8) + b);
}

static unsigned int	choose_color(t_param *p, t_inter check[], t_vec ray)
{
	unsigned int	pixel;
	int				wall;
	float			w;
	float			h;

	wall = find_card(p, check, ray, &pixel);
	if (wall < 0 || wall > 6)
		return (0x000000);
	if (wall != 6)
	{
		w = check[wall].r_w;
		h = check[wall].r_h;
		if (p->mlx->walls[wall].wall)
			pixel = ft_get_pixel(p->mlx->walls[wall].texture, \
					w * p->mlx->walls[wall].texture.w, \
					h * p->mlx->walls[wall].texture.h);
		else
			pixel = p->mlx->walls[wall].color;
	}
	return (average_color(pixel, check[wall].t));
}

unsigned int	ray_casting(t_param *p, t_vec ray)
{
	t_line	line;
	t_inter	check[7];

	line = line_create_point_vec(p->map->player, ray);
	check[0] = (t_inter){-1, -1, -1};
	check[1] = (t_inter){-1, -1, -1};
	check[2] = (t_inter){-1, -1, -1};
	check[3] = (t_inter){-1, -1, -1};
	check[4] = (t_inter){-1, -1, -1};
	check[5] = (t_inter){-1, -1, -1};
	check[6] = (t_inter){-1, -1, -1};
	if (ray.y < 0)
		check[0].t = intersec_planes_n(p, line, &check[0].r_w, &check[0].r_h);
	else if (ray.y)
		check[1].t = intersec_planes_s(p, line, &check[1].r_w, &check[1].r_h);
	if (ray.x < 0)
		check[2].t = intersec_planes_w(p, line, &check[2].r_w, &check[2].r_h);
	else if (ray.x)
		check[3].t = intersec_planes_e(p, line, &check[3].r_w, &check[3].r_h);
	check[4].t = intersec_plane_c(p, line, &check[4].r_w, &check[4].r_h);
	check[5].t = intersec_plane_f(p, line, &check[5].r_w, &check[5].r_h);
	return (choose_color(p, check, ray));
}
