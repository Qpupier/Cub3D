/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:24:44 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/31 15:29:21 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rays(t_param *p)
{
	int	size;
	int	i;

	size = p->win->w * p->win->h;
	p->rays = malloc(sizeof(t_vec) * size);
	if (!p->rays)
		ft_error_free(p, "Malloc error - Init rays");
	p->free |= F_RAYS;
	i = -1;
	while (++i < size)
		p->rays[i] = vec_normalize((t_vec){
				.x = p->win->r_fov_h * (i % p->win->w - p->win->w05),
				.y = -1,
				.z = -p->win->r_fov_v * (i / p->win->w - p->win->h05)
			});
}

static void	init_win(t_param *p)
{
	p->win->w05 = p->win->w * 0.5;
	p->win->h05 = p->win->h * 0.5;
	p->win->fov_v = 2 * tan(p->win->fov_h * p->win->h * 0.5 / p->win->w);
	if (p->win->fov_v < 0)
		p->win->fov_v = -p->win->fov_v;
	if (p->win->fov_h > 2 || p->win->fov_v > 1)
		ft_putendl("Beware, this field of vision is not humanly possible !");
	p->win->r_fov_h = p->win->fov_h / p->win->w;
	p->win->r_fov_v = p->win->fov_v / p->win->h;
}

static void	init_map(t_param *p)
{
	p->map->p_n = malloc(sizeof(int) * (p->map->h + 1));
	if (!p->map->p_n)
		ft_error_free(p, "Malloc error - North map array");
	p->free |= F_MAP_PN;
	p->map->p_s = malloc(sizeof(int) * (p->map->h + 1));
	if (!p->map->p_s)
		ft_error_free(p, "Malloc error - South map array");
	p->free |= F_MAP_PS;
	p->map->p_e = malloc(sizeof(int) * (p->map->w + 1));
	if (!p->map->p_e)
		ft_error_free(p, "Malloc error - East map array");
	p->free |= F_MAP_PE;
	p->map->p_w = malloc(sizeof(int) * (p->map->w + 1));
	if (!p->map->p_w)
		ft_error_free(p, "Malloc error - West map array");
	p->free |= F_MAP_PW;
}

static void	init_range(t_win *win, int w, int h)
{
	if (w < win->w)
		win->w = w;
	if (h < win->h)
		win->h = h;
	win->w_scale = win->w;
	win->h_scale = win->h;
	win->w /= SCALE;
	win->h /= SCALE;
}

void	init_parameters(t_param *p)
{
	int	w;
	int	h;

	if (mlx_get_screen_size(p->mlx->mlx_ptr, &w, &h))
		ft_error_free(p, "Minilibx error - Impossible to get screen size");
	init_range(p->win, w, h);
	p->mlx->win_ptr = mlx_new_window(p->mlx->mlx_ptr, p->win->w_scale, \
			p->win->h_scale, "Cub3D");
	if (!p->mlx->win_ptr)
		ft_error_free(p, "Minilibx error - Impossible to open a window");
	p->free |= F_MLX_WIN;
	if (!ft_create_img(p->mlx->mlx_ptr, &p->mlx->img, p->win->w_scale, \
			p->win->h_scale))
		ft_error_free(p, "Minilibx error - Impossible to create an image");
	p->free |= F_MLX_IMG;
	init_win(p);
	init_map(p);
	init_rays(p);
	init_rays_theta(p);
	ft_putendl("Start game");
}
