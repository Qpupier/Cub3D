/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:03:09 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/12 18:27:11 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_card(t_inter check[])
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
	return (card);
}

static unsigned int	choose_color(t_param *p, int wall, t_inter check[])
{
	float	w;
	float	h;

	if (wall < 0 || wall > 5)
		return (0x000000);
	w = check[wall].r_w;
	h = check[wall].r_h;
	if (wall == C_N)
	{
		return (ft_get_pixel(p->mlx->no, w * p->mlx->no.w, h * p->mlx->no.h));
		return (0xffffff);
	}
	else if (wall == C_S)
	{
		return (ft_get_pixel(p->mlx->so, w * p->mlx->so.w, h * p->mlx->so.h));
		return (0xff0000);
	}
	else if (wall == C_W)
	{
		return (ft_get_pixel(p->mlx->we, w * p->mlx->we.w, h * p->mlx->we.h));
		return (0x00ff00);
	}
	else if (wall == C_E)
	{
		return (ft_get_pixel(p->mlx->ea, w * p->mlx->ea.w, h * p->mlx->ea.h));
		return (0x00ff00);
	}
	else if (wall == C_C)
	{
		return (ft_get_pixel(p->mlx->so, w * p->mlx->so.w, h * p->mlx->so.h));
		return (0x00ff00);
	}
	else if (wall == C_F)
	{
		return (ft_get_pixel(p->mlx->no, w * p->mlx->no.w, h * p->mlx->no.h));
		return (0x0000ff);
	}
	return (0x000000);
}

unsigned int	ray_casting(t_param *p, t_vec ray)
{
	t_line	line;
	t_inter	check[6];

	line = line_create_point_vec(p->map->player, ray);
	check[0] = (t_inter){-1, -1, -1};
	check[1] = (t_inter){-1, -1, -1};
	check[2] = (t_inter){-1, -1, -1};
	check[3] = (t_inter){-1, -1, -1};
	check[4] = (t_inter){-1, -1, -1};
	check[5] = (t_inter){-1, -1, -1};
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
	return (choose_color(p, find_card(check), check));
}
