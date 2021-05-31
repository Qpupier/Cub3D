/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:17:00 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/31 16:03:52 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*init_thread(void *ptr)
{
	t_multithread	*thread;
	t_vec			move[4];
	t_vec			newton;
	short int		i;

	move[0] = (t_vec){0, -SPEED, 0};
	move[1] = (t_vec){-SPEED, 0, 0};
	move[2] = (t_vec){0, SPEED, 0};
	move[3] = (t_vec){SPEED, 0, 0};
	newton = (t_vec){1, 0, 0};
	thread = ptr;
	i = thread->i_start - 1;
	while (++i < thread->i_end)
	{
		thread->p->trigo_cos[i] = cos(i * thread->p->rad);
		thread->p->trigo_sin[i] = sin(i * thread->p->rad);
		thread->p->pre_move[0][i] = vec_rot_z_pre(thread->p, move[0], i);
		thread->p->pre_move[1][i] = vec_rot_z_pre(thread->p, move[1], i);
		thread->p->pre_move[2][i] = vec_rot_z_pre(thread->p, move[2], i);
		thread->p->pre_move[3][i] = vec_rot_z_pre(thread->p, move[3], i);
		thread->p->pre_move[4][i] = vec_rot_z_pre(thread->p, newton, i);
	}
	return (ptr);
}

void	init_trigo(t_param *p)
{
	pthread_t		thread[NB_THREADS];
	t_multithread	data[NB_THREADS];
	short int		i;

	i = -1;
	while (++i < NB_THREADS)
	{
		data[i] = (t_multithread){p, 360 * (i + 1) / NB_THREADS, \
				360 * i / NB_THREADS};
		if (i == NB_THREADS - 1)
			data[i].i_end = 360;
		if (pthread_create(&thread[i], NULL, &init_thread, &data[i]))
			ft_error_free(p, \
					"Multithreading error \
					- Impossible to create threads (parsing)");
	}
	while (i--)
		if (pthread_join(thread[i], NULL))
			ft_error_free(p, \
					"Multithreading error \
					- Impossible to join threads (parsing)");
}

static void	*init_rays_theta_thread(void *ptr)
{
	t_multithread	*thread;
	int				i;
	short int		theta;

	thread = ptr;
	theta = thread->i_start - 1;
	while (++theta < thread->i_end)
	{
		thread->p->rays_theta[theta] = malloc(sizeof(t_vec) \
				* thread->p->win->w * thread->p->win->h);
		if (!thread->p->rays_theta[theta])
			ft_error_free_array(thread->p, theta, \
					"Malloc error - Init rays_theta");
		i = -1;
		while (++i < thread->p->win->w * thread->p->win->h)
			thread->p->rays_theta[theta][i] \
					= vec_rot_x_pre(thread->p, thread->p->rays[i], theta);
	}
	return (ptr);
}

void	init_rays_theta(t_param *p)
{
	pthread_t		thread[NB_THREADS];
	t_multithread	data[NB_THREADS];
	short int		i;

	p->rays_theta = malloc(sizeof(t_vec *) * 360);
	if (!p->rays_theta)
		ft_error_free_array(p, -1, "Malloc error - Init rays_theta");
	i = -1;
	while (++i < NB_THREADS)
	{
		data[i] = (t_multithread){p, 360 * (i + 1) / NB_THREADS, \
				360 * i / NB_THREADS};
		if (i == NB_THREADS - 1)
			data[i].i_end = 360;
		if (pthread_create(&thread[i], NULL, &init_rays_theta_thread, &data[i]))
			ft_error_free(p, \
					"Multithreading error \
					- Impossible to create threads (precomputing rays)");
	}
	while (i--)
		if (pthread_join(thread[i], NULL))
			ft_error_free(p, \
					"Multithreading error \
					- Impossible to join threads (precomputing rays)");
	p->free |= F_RAYS_THETA;
}
