/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:39:14 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/11 14:09:59 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_image(t_param *p, const char *error, int one, void *img_ptr)
{
	p->free ^= one;
	(void)error;
	(void)img_ptr;
	// if (mlx_destroy_image(p->mlx->mlx_ptr, img_ptr))
		// ft_error_free(p, error);
}

void	free_window(t_param *p, const char *error, int one, void *win_ptr)
{
	p->free ^= one;
	(void)error;
	(void)win_ptr;
	// if (mlx_destroy_window(p->mlx->mlx_ptr, win_ptr))
		// ft_error_free(p, error);
}

void	free_fd(t_param *p, const char *error)
{
	p->free ^= F_CLOSE;
	if (close(p->fd) == -1)
		ft_error_free(p, error);
}

void	free_one(t_param *p, void *ptr, int one)
{
	free(ptr);
	p->free ^= one;
}
