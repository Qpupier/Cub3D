/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:06:25 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/23 09:45:42 by qpupier          ###   ########lyon.fr   */
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
	while (++i < 4)
	{
		if (check[i].t > 0 && (dis < 0 || check[i].t <= dis))
		{
			dis = check[i].t;
			card = i;
		}
	}
	return (card);
}

static uint32_t	choose_color(t_param *p, int wall, t_inter check[])
{
	float	w;
	float	h;

	if (wall < 0 || wall > 3)
		return (0x000000);
	w = check[wall].r_w;
	h = check[wall].r_h;
	if (!wall)
	{
		return (ft_get_pixel(p->mlx->ea, w * p->mlx->ea.w, h * p->mlx->ea.h));
		return (0xffffff);
	}
	if (wall == 1)
	{
		return (ft_get_pixel(p->mlx->we, w * p->mlx->we.w, h * p->mlx->we.h));
		return (0xff0000);
	}
	if (wall == 2)
	{
		return (ft_get_pixel(p->mlx->so, w * p->mlx->so.w, h * p->mlx->so.h));
		return (0x00ff00);
	}
	return (ft_get_pixel(p->mlx->no, w * p->mlx->no.w, h * p->mlx->no.h));
	return (0x0000ff);
	(void)p;
}

static uint32_t	ray_casting(t_param *p, t_vec ray)
{
	t_line	line;
	t_inter	check[4];

	line = line_create_point_vec(p->map->player, ray);
	check[0] = (t_inter){-1, -1, -1};
	check[1] = (t_inter){-1, -1, -1};
	check[2] = (t_inter){-1, -1, -1};
	check[3] = (t_inter){-1, -1, -1};
	if (ray.x > 0)
		check[0].t = intersec_planes_e(p, line, &check[0].r_w, &check[0].r_h);
	else if (ray.x)
		check[1].t = intersec_planes_w(p, line, &check[1].r_w, &check[1].r_h);
	if (ray.y > 0)
		check[2].t = intersec_planes_s(p, line, &check[2].r_w, &check[2].r_h);
	else if (ray.y)
		check[3].t = intersec_planes_n(p, line, &check[3].r_w, &check[3].r_h);
	return (choose_color(p, find_card(check), check));
}

int	algo(t_param *p)
{
	t_vec	ray;
	int		i;
	int		j;

	events(p);
	j = -1;
	while (++j < p->win->h)
	{
		i = -1;
		while (++i < p->win->w)
		{
			ray = vec_rot_x(p->rays[j * p->win->w + i], p->angle_v);//PRECALCUL
			ray = vec_rot_z(ray, p->angle_h);//
			ft_pixel_put(p->mlx->img, i, j, ray_casting(p, ray));
		}
	}
	if (mlx_put_image_to_window(p->mlx->mlx_ptr, p->mlx->win_ptr, \
			p->mlx->img.ptr, 0, 0))
		ft_error_free(p, "Mlx error - Impossible to put image to window");
	if (mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, p->mlx->win_ptr))
		ft_error_free(p, "Mlx error - Impossible to synchronize the window");
	return (0);
}
