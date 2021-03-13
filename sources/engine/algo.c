/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:06:25 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/13 16:43:49 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_card(float check[])
{
	float	dis;
	int		card;
	int		i;

	dis = -1;
	card = -1;
	i = -1;
	while (++i < 4)
		if (check[i] > 0 && (dis < 0 || check[i] < dis))
		{
			dis = check[i];
			card = i;
		}
	return (card);
}

static uint32_t	ray_casting(t_param *p, t_vec ray)
{
	t_vec result;
	int	i;
	t_line line = line_create_point_vec(p->map->player, ray);
	int	x;
	int	y;
	float	t;
	float	check[4] = {-1, -1, -1, -1};

	if (ray.x >= 0)
	{
		i = (int)p->map->player.x;
		while (++i <= p->map->w)
			if (inter_line_plane(line, p->map->p_e[i].p, &result, &t) && t > 0 && result.z >= 0 && result.z < 1)
			{
				x = (int)-p->map->p_e[i].p.d;
				y = (int)result.y;
				if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h && p->map->map[y][x])
				{
					check[0] = t;
					break ;
				}
			}
	}
	else
	{
		i = (int)p->map->player.x + 1;
		while (i--)
			if (inter_line_plane(line, p->map->p_w[i].p, &result, &t) && t > 0 && result.z >= 0 && result.z < 1)
			{
				x = (int)-p->map->p_w[i].p.d - 1;
				y = (int)result.y;
				if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h && p->map->map[y][x])
				{
					check[1] = t;
					break ;
				}
			}
	}
	if (ray.y >= 0)
	{
		i = (int)p->map->player.y;
		while (++i <= p->map->h)
			if (inter_line_plane(line, p->map->p_s[i].p, &result, &t) && t > 0 && result.z >= 0 && result.z < 1)
			{
				x = (int)result.x;
				y = (int)-p->map->p_s[i].p.d;
				if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h && p->map->map[y][x])
				{
					check[2] = t;
					break ;
				}
			}
	}
	else
	{
		i = (int)p->map->player.y + 1;
		while (i--)
			if (inter_line_plane(line, p->map->p_n[i].p, &result, &t) && t > 0 && result.z >= 0 && result.z < 1)
			{
				x = (int)result.x;
				y = (int)-p->map->p_n[i].p.d - 1;
				if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h && p->map->map[y][x])
				{
					check[3] = t;
					break ;
				}
			}
	}
	int wall = find_card(check);
	if (!wall)
		return (0xffffff);
	if (wall == 1)
		return (0xff0000);
	if (wall == 2)
		return (0x00ff00);
	if (wall == 3)
		return (0x0000ff);
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
