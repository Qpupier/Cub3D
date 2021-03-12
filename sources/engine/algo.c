/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:06:25 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/12 23:29:40 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	ray_casting(t_param *p, t_vec ray)
{
	t_vec result;
	// t_plane p1 = {0, 1, 0, 3};
	// t_plane p2 = {1, 0, 0, -2};
	// t_plane p3 = {0, 1, 0, -3};
	// t_plane p4 = {1, 0, 0, 2};
	int	i;

	// if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p1, &result) && result.z >= 0 && result.z < 1)
	// 	return (0xffffff);
	// if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p2, &result) && result.z >= 0 && result.z < 1)
	// 	return (0xffffff);
	// if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p3, &result) && result.z >= 0 && result.z < 1)
	// 	return (0xffffff);
	// if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p4, &result) && result.z >= 0 && result.z < 1)
	// 	return (0xffffff);
	t_vec pos = p->map->player;
	t_line line = line_create_point_vec(pos, ray);
	int	x;
	int	y;
	// printf("%f, %f, %f\n", pos.x, pos.y, pos.z);
	// t_vec	sol;
	// float t = -1;
	if (ray.x >= 0)
	{
		i = (int)pos.x;
		while (++i <= p->map->w)
			if (inter_line_plane(line, p->map->p_e[i].p, &result) && result.z >= 0 && result.z < 1)
			{
				x = (int)-p->map->p_e[i].p.d;
				y = (int)result.y;
				if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h && p->map->map[y][x])
				{
					return (0xff0000);
				}
			}
	}
	else
	{
		i = (int)pos.x + 1;
		while (i--)
			if (inter_line_plane(line, p->map->p_w[i].p, &result) && result.z >= 0 && result.z < 1)
			{
				x = (int)-p->map->p_w[i].p.d - 1;
				y = (int)result.y;
				if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h && p->map->map[y][x])
					return (0x00ff00);
			}
	}
	if (ray.y >= 0)
	{
		i = (int)pos.y;
		while (++i <= p->map->h)
			if (inter_line_plane(line, p->map->p_s[i].p, &result) && result.z >= 0 && result.z < 1)
			{
				x = (int)result.x;
				y = (int)-p->map->p_s[i].p.d;
				if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h && p->map->map[y][x])
					return (0x0000ff);
			}
	}
	else
	{
		i = (int)pos.y + 1;
		while (i--)
			if (inter_line_plane(line, p->map->p_n[i].p, &result) && result.z >= 0 && result.z < 1)
			{
				x = (int)result.x;
				y = (int)-p->map->p_n[i].p.d - 1;
				if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h && p->map->map[y][x])
					return (0xffffff);
			}
	}
	return (0x000000);
}

void	algo(t_param *p)
{
	t_vec	ray;
	int		i;
	int		j;

	j = -1;
	while (++j < p->win->h)
	{
		i = -1;
		while (++i < p->win->w)
		{
			ray = vec_rot_z(p->rays[j * p->win->w + i], p->angle);
			ft_pixel_put(p->mlx->img, i, j, ray_casting(p, ray));
		}
	}
	mlx_put_image_to_window(p->mlx->mlx_ptr, p->mlx->win_ptr, p->mlx->img.ptr,
		0, 0);
}
