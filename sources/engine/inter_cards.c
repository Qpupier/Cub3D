/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cards.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:06:30 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/23 09:43:07 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	in_map(t_map *map, int x, int y)
{
	return (x >= 0 && x < map->w && y >= 0 && y < map->h && map->map[y][x]);
}

float	intersec_planes_e(t_param *p, t_line line, float *r_w, float *r_h)
{
	int			i;
	t_vec		result;
	float		t;
	int			x;
	int			y;

	i = p->map->player.x;
	if (i < -1)
		i = -1;
	while (++i <= p->map->w)
	{
		if (inter_line_plane_x(line, p->map->p_e[i].p, &result, &t) && t > 0 \
				&& result.z >= 0 && result.z < 1 && result.y >= 0)
		{
			x = i;
			y = result.y;
			if (in_map(p->map, x, y))
			{
				*r_w = result.y - y;
				*r_h = 1 - result.z;
				return (t);
			}
		}
	}
	return (-1);
}

float	intersec_planes_w(t_param *p, t_line line, float *r_w, float *r_h)
{
	int			i;
	t_vec		result;
	float		t;
	int			x;
	int			y;

	i = p->map->player.x + 1;
	if (i > p->map->w + 1)
		i = p->map->w + 1;
	while (i-- >= 0)
	{
		if (inter_line_plane_x(line, p->map->p_w[i].p, &result, &t) && t > 0 \
				&& result.z >= 0 && result.z < 1 && result.y >= 0)
		{
			x = i - 1;
			y = result.y;
			if (in_map(p->map, x, y))
			{
				*r_w = 1 - result.y + y;
				*r_h = 1 - result.z;
				return (t);
			}
		}
	}
	return (-1);
}

float	intersec_planes_s(t_param *p, t_line line, float *r_w, float *r_h)
{
	int			i;
	t_vec		result;
	float		t;
	int			x;
	int			y;

	i = p->map->player.y;
	if (i < -1)
		i = -1;
	while (++i <= p->map->h)
	{
		if (inter_line_plane_y(line, p->map->p_s[i].p, &result, &t) && t > 0 \
				&& result.z >= 0 && result.z < 1 && result.x >= 0)
		{
			x = result.x;
			y = i;
			if (in_map(p->map, x, y))
			{
				*r_w = 1 - result.x + x;
				*r_h = 1 - result.z;
				return (t);
			}
		}
	}
	return (-1);
}

float	intersec_planes_n(t_param *p, t_line line, float *r_w, float *r_h)
{
	int			i;
	t_vec		result;
	float		t;
	int			x;
	int			y;

	i = p->map->player.y + 1;
	if (i > p->map->h + 1)
		i = p->map->h + 1;
	while (i-- >= 0)
	{
		if (inter_line_plane_y(line, p->map->p_n[i].p, &result, &t) && t > 0 \
				&& result.z >= 0 && result.z < 1 && result.x >= 0)
		{
			x = result.x;
			y = i - 1;
			if (in_map(p->map, x, y))
			{
				*r_w = result.x - x;
				*r_h = 1 - result.z;
				return (t);
			}
		}
	}
	return (-1);
}
