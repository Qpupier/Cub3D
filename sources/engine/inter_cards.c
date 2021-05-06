/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cards.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:06:30 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/04 16:50:24 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline short int	in_map(t_map *map, int x, int y)
{
	return (x >= 0 && x < map->w && y >= 0 && y < map->h && map->map[y][x]);
}

float	intersec_planes_e(t_param *p, t_line line, float *r_w, float *r_h)
{
	int			i;
	t_vec		result;
	float		t;
	int			y;

	i = p->map->player.x;
	if (i < -1)
		i = -1;
	while (++i <= p->map->w)
	{
		if (p->map->p_e[i] && inter_line_plane_x(line, -i, &result, &t) \
				&& t > 0 && result.y >= 0)
		{
			if (inter_break(p->map->player.z, result.z))
				return (-1);
			y = result.y;
			if (in_map(p->map, i, y))
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
	int			y;

	i = p->map->player.x + 1;
	if (i > p->map->w + 1)
		i = p->map->w + 1;
	while (i-- >= 0)
	{
		if (p->map->p_w[i] && inter_line_plane_x(line, -i, &result, &t) \
				&& t > 0 && result.y >= 0)
		{
			if (inter_break(p->map->player.z, result.z))
				return (-1);
			y = result.y;
			if (in_map(p->map, i - 1, y))
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

	i = p->map->player.y;
	if (i < -1)
		i = -1;
	while (++i <= p->map->h)
	{
		if (p->map->p_s[i] && inter_line_plane_y(line, -i, &result, &t) \
				&& t > 0 && result.x >= 0)
		{
			if (inter_break(p->map->player.z, result.z))
				return (-1);
			x = result.x;
			if (in_map(p->map, x, i))
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

	i = p->map->player.y + 1;
	if (i > p->map->h + 1)
		i = p->map->h + 1;
	while (i-- >= 0)
	{
		if (p->map->p_n[i] && inter_line_plane_y(line, -i, &result, &t) \
				&& t > 0 && result.x >= 0)
		{
			if (inter_break(p->map->player.z, result.z))
				return (-1);
			x = result.x;
			if (in_map(p->map, x, i - 1))
			{
				*r_w = result.x - x;
				*r_h = 1 - result.z;
				return (t);
			}
		}
	}
	return (-1);
}
