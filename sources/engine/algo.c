/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:06:25 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/31 15:59:28 by qpupier          ###   ########lyon.fr   */
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
	{
		if (p->fps > 59)
			p->fps = 60;
		string = p->mlx->strings_fps[p->fps - 1];
	}
	else
		string = "FPS : 0";
	if (mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 10, 20, 0xFFFFFF, \
			string))
		ft_error_free(p, "Mlx error - Impossible to put string to window");
	if (mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, p->mlx->win_ptr))
		ft_error_free(p, "Mlx error - Impossible to synchronize the window");
}

static void	*algo_loop(void *ptr)
{
	t_multithread	*t;
	t_vec			ray;
	int				i;
	int				j;

	t = ptr;
	j = -1;
	while (++j < t->p->win->h)
	{
		i = t->i_start - 1;
		while (++i < t->i_end)
		{
			ray = vec_rot_z_pre(t->p, \
					t->p->rays_theta[t->p->angle_v][j * t->p->win->w + i], \
					t->p->angle_h);
			ft_pixel_put(t->p->mlx->img, i, j, ray_casting(t->p, ray));
		}
	}
	return (ptr);
}

int	algo(t_param *p)
{
	pthread_t		thread[NB_THREADS];
	t_multithread	data[NB_THREADS];
	int				i;

	events(p);
	fps(p);
	sprites(p->map);
	i = -1;
	while (++i < NB_THREADS)
	{
		data[i] = (t_multithread){p, p->win->w * (i + 1) / NB_THREADS, \
				p->win->w * i / NB_THREADS};
		if (i == NB_THREADS - 1)
			data[i].i_end = p->win->w;
		if (pthread_create(&thread[i], NULL, &algo_loop, &data[i]))
			ft_error_free(p, \
					"Multithreading error - Impossible to create threads");
	}
	while (i--)
		if (pthread_join(thread[i], NULL))
			ft_error_free(p, \
					"Multithreading error - Impossible to join threads");
	display(p);
	return (0);
}
