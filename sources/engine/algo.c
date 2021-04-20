/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:06:25 by qpupier           #+#    #+#             */
/*   Updated: 2021/04/20 13:54:29 by qpupier          ###   ########lyon.fr   */
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
		if (check[i].t > 0 && (dis < 0 || check[i].t <= dis))
		{
			dis = check[i].t;
			card = i;
		}
	return (card);
}

static int	inter_line_plane_x(t_line l, t_plane p, t_vec *result, float *t)
{
	float	tmp;

	tmp = p.a * l.u.x;
	if (!tmp)
		return (0);
	*t = -(p.a * l.o.x + p.d) / tmp;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}

static int	inter_line_plane_y(t_line l, t_plane p, t_vec *result, float *t)
{
	float	tmp;

	tmp = p.b * l.u.y;
	if (!tmp)
		return (0);
	*t = -(p.b * l.o.y + p.d) / tmp;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}

/*static int	inter_line_plane_z(t_line l, t_plane p, t_vec *result, float *t)
{
	float	tmp;

	tmp = p.c * l.u.z;
	if (!tmp)
		return (0);
	*t = -(p.c * l.o.z + p.d) / tmp;
	*result = vec_add(l.o, vec_mult_float(l.u, *t));
	return (1);
}*/

static float	intersec_planes_e(t_param *p, t_line line, float *r_w, \
		float *r_h)
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
		if (inter_line_plane_x(line, p->map->p_e[i].p, &result, &t) && t > 0 \
				&& result.z >= 0 && result.z < 1)
		{
			x = i;
			y = result.y;
			if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h
				&& p->map->map[y][x])
			{
				*r_w = result.y - y;
				*r_h = 1 - result.z;
				return (t);
			}
		}
	return (-1);
}

static float	intersec_planes_w(t_param *p, t_line line, float *r_w, \
		float *r_h)
{
	int			i;
	t_vec		result;
	float		t;
	int			x;
	int			y;

	i = p->map->player.x + 1;
	if (i > p->map->w + 1)
		i = p->map->w + 1;
	while (i--)
		if (inter_line_plane_x(line, p->map->p_w[i].p, &result, &t) && t > 0 \
				&& result.z >= 0 && result.z < 1)
		{
			x = i - 1;
			y = result.y;
			if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h \
					&& p->map->map[y][x])
			{
				*r_w = 1 - result.y + y;
				*r_h = 1 - result.z;
				return (t);
			}
		}
	return (-1);
}

static float	intersec_planes_s(t_param *p, t_line line, float *r_w, \
		float *r_h)
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
		if (inter_line_plane_y(line, p->map->p_s[i].p, &result, &t) && t > 0 \
				&& result.z >= 0 && result.z < 1)
		{
			x = result.x;
			y = i;
			if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h \
					&& p->map->map[y][x])
			{
				*r_w = 1 - result.x + x;
				*r_h = 1 - result.z;
				return (t);
			}
		}
	return (-1);
}

static float	intersec_planes_n(t_param *p, t_line line, float *r_w, \
		float *r_h)
{
	int			i;
	t_vec		result;
	float		t;
	int			x;
	int			y;

	i = p->map->player.y + 1;
	if (i > p->map->h + 1)
		i = p->map->h + 1;
	while (i--)
		if (inter_line_plane_y(line, p->map->p_n[i].p, &result, &t) && t > 0 \
				&& result.z >= 0 && result.z < 1)
		{
			x = result.x;
			y = i - 1;
			if (x >= 0 && x < p->map->w && y >= 0 && y < p->map->h \
					&& p->map->map[y][x])
			{
				*r_w = result.x - x;
				*r_h = 1 - result.z;
				return (t);
			}
		}
	return (-1);
}

static uint32_t	choose_color(t_param *p, int wall, t_inter check[])
{
	if (wall > -1)
		return (ft_get_pixel(p->mlx->no, check[wall].r_w * p->mlx->no.w, check[wall].r_h * p->mlx->no.h));
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

static uint32_t	ray_casting(t_param *p, t_vec ray)
{
	t_line line;
	t_inter	check[4];

	line = line_create_point_vec(p->map->player, ray);
	check[0] = (t_inter){-1, -1, -1};
	check[1] = (t_inter){-1, -1, -1};
	check[2] = (t_inter){-1, -1, -1};
	check[3] = (t_inter){-1, -1, -1};
	if (ray.x >= 0)
		check[0].t = intersec_planes_e(p, line, &check[0].r_w, &check[0].r_h);
	else
		check[1].t = intersec_planes_w(p, line, &check[1].r_w, &check[1].r_h);
	if (ray.y >= 0)
		check[2].t = intersec_planes_s(p, line, &check[2].r_w, &check[2].r_h);
	else
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
