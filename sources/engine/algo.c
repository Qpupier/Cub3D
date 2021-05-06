/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:06:25 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/06 17:12:50 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fps(t_param *p)
{
	unsigned long int	t;

	t = time(NULL);
	if (!p->mlx->time)
		p->mlx->time = t;
	if (t == p->mlx->time)
		p->mlx->fps++;
	else
	{
		p->fps = p->mlx->fps;
		p->mlx->time = t;
		p->mlx->fps = 1;
	}
}

static void	display(t_param *p)
{
	char	*string;

	if (mlx_put_image_to_window(p->mlx->mlx_ptr, p->mlx->win_ptr, \
			p->mlx->img.ptr, 0, 0))
		ft_error_free(p, "Mlx error - Impossible to put image to window");
	if (p->fps > 0)
		string = p->mlx->strings_fps[p->fps - 1];
	else
		string = "FPS : 0";
	if (mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 10, 20, 0xFFFFFF, \
			string))
		ft_error_free(p, "Mlx error - Impossible to put string to window");
	if (mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, p->mlx->win_ptr))
		ft_error_free(p, "Mlx error - Impossible to synchronize the window");
}

int	algo(t_param *p)
{
	t_vec	ray;
	int		i;
	int		j;

	events(p);
	fps(p);
	j = -1;
	while (++j < p->win->h)
	{
		i = -1;
		while (++i < p->win->w)
		{
			ray = vec_rot_z_pre(p, \
					p->rays_theta[p->angle_v][j * p->win->w + i], p->angle_h);
			ft_pixel_put(p->mlx->img, i, j, ray_casting(p, ray));
		}
	}
	display(p);
	return (0);
}
