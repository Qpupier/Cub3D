/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:06:25 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/11 18:09:59 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	ray_casting(t_vec ray)
{
	t_vec result;
	t_plane p1 = {0, 1, 0, 3};
	t_plane p2 = {1, 0, 0, -2};
	t_plane p3 = {0, 1, 0, -3};
	t_plane p4 = {1, 0, 0, 2};
	
	if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p1, &result) && result.z >= 0 && result.z < 1)
		return (0xffffff);
	if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p2, &result) && result.z >= 0 && result.z < 1)
		return (0xffffff);
	if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p3, &result) && result.z >= 0 && result.z < 1)
		return (0xffffff);
	if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p4, &result) && result.z >= 0 && result.z < 1)
		return (0xffffff);
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
			ft_pixel_put(p->mlx->img, i, j, ray_casting(ray));
		}
	}
	mlx_put_image_to_window(p->mlx->mlx_ptr, p->mlx->win_ptr, p->mlx->img.ptr,
		0, 0);
}
