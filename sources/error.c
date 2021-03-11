/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:40:27 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/11 20:00:21 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_mlx(t_param *p)
{
	if (p->free & F_MLX_IMG)
		free_image(p, "Impossible to destroy image", F_MLX_IMG,
			p->mlx->img.ptr);
	if (p->free & F_MLX_NO)
		free_image(p, "Impossible to destroy image (NORTH)", F_MLX_NO,
			p->mlx->no.ptr);
	if (p->free & F_MLX_SO)
		free_image(p, "Impossible to destroy image (SOUTH)", F_MLX_SO,
			p->mlx->so.ptr);
	if (p->free & F_MLX_WE)
		free_image(p, "Impossible to destroy image (WEST)", F_MLX_WE,
			p->mlx->we.ptr);
	if (p->free & F_MLX_EA)
		free_image(p, "Impossible to destroy image (EAST)", F_MLX_EA,
			p->mlx->ea.ptr);
	if (p->free & F_MLX_S)
		free_image(p, "Impossible to destroy image (SPRITE)", F_MLX_S,
			p->mlx->s.ptr);
	if (p->free & F_MLX_WIN)
		free_window(p, "Impossible to destroy window", F_MLX_WIN,
			p->mlx->win_ptr);
	if (p->free & F_MLX_PTR)
		free_one(p, p->mlx->mlx_ptr, F_MLX_PTR);
	free_one(p, p->mlx, F_MLX);
}

void	free_map(t_param *p)
{
	int	i;

	if (p->free & F_MAP_MAP)
	{
		i = -1;
		while (++i < p->map->h)
			free(p->map->map[i]);
		free_one(p, p->map->map, F_MAP_MAP);
	}
	if (p->free & F_MAP_PN)
		free_one(p, p->map->p_n, F_MAP_PN);
	if (p->free & F_MAP_PS)
		free_one(p, p->map->p_s, F_MAP_PS);
	if (p->free & F_MAP_PE)
		free_one(p, p->map->p_e, F_MAP_PE);
	if (p->free & F_MAP_PW)
		free_one(p, p->map->p_w, F_MAP_PW);
	free_one(p, p->map, F_MAP);
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
	if (p->free & F_SPRITES)
		free_one(p, p->sprites, F_SPRITES);
	if (p->free & F_CLOSE)
		free_fd(p, "Impossible to close map file");
	free(p);
}

void	ft_error_free(t_param *p, const char *error)
{
	free_all(p);
	ft_error(error);
}
