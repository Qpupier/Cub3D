/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:40:27 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 16:42:05 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_mlx_walls_tex(t_param *p)
{
	if (p->free & F_MLX_NO)
		free_image(p, "Impossible to destroy image (NORTH)", F_MLX_NO, \
				p->mlx->walls[C_N].texture.ptr);
	if (p->free & F_MLX_SO)
		free_image(p, "Impossible to destroy image (SOUTH)", F_MLX_SO, \
				p->mlx->walls[C_S].texture.ptr);
	if (p->free & F_MLX_WE)
		free_image(p, "Impossible to destroy image (WEST)", F_MLX_WE, \
				p->mlx->walls[C_W].texture.ptr);
	if (p->free & F_MLX_EA)
		free_image(p, "Impossible to destroy image (EAST)", F_MLX_EA, \
				p->mlx->walls[C_E].texture.ptr);
	if (p->free & F_MLX_F)
		free_image(p, "Impossible to destroy image (FLOOR)", F_MLX_F, \
				p->mlx->walls[C_F].texture.ptr);
	if (p->free & F_MLX_C)
		free_image(p, "Impossible to destroy image (CEIL)", F_MLX_C, \
				p->mlx->walls[C_C].texture.ptr);
}

static void	free_mlx(t_param *p)
{
	if (p->free & F_MLX_IMG)
		free_image(p, "Impossible to destroy image", F_MLX_IMG, \
				p->mlx->img.ptr);
	if (p->free & F_MLX_SPRITE)
		free_image(p, "Impossible to destroy image (SPRITE)", F_MLX_SPRITE, \
				p->mlx->sprite.texture.ptr);
	free_mlx_walls_tex(p);
	if (p->free & F_MLX_WIN)
		free_window(p, "Impossible to destroy window", F_MLX_WIN, \
				p->mlx->win_ptr);
	if (p->free & F_MLX_PTR)
		free_one(p, p->mlx->mlx_ptr, F_MLX_PTR);
	free_one(p, p->mlx, F_MLX);
}

void	free_all(t_param *p)
{
	if (p->free & F_MLX)
		free_mlx(p);
	if (p->free & F_WIN)
		free_one(p, p->win, F_WIN);
	if (p->free & F_MAP)
		free_map(p);
	if (p->free & F_RAYS)
		free_one(p, p->rays, F_RAYS);
	if (p->free & F_RAYS_THETA)
		free_rays_theta(p);
	if (p->free & F_NEWTON)
		free_one(p, p->jump, F_NEWTON);
	if (p->free & F_CLOSE)
		free_fd(p, "Impossible to close map file");
	free(p);
}

void	ft_error_free(t_param *p, const char *error)
{
	free_all(p);
	ft_error(error);
}

void	ft_error_free_array(t_param *p, int theta, const char *error)
{
	int	i;

	i = -1;
	while (++i <= theta)
		free(p->rays_theta[i]);
	free(p->rays_theta);
	ft_error_free(p, error);
}
