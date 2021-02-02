/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:53:10 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/02 17:53:45 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	ray_casting(t_vec ray)
{
	t_vec result;
	t_plane p1 = {0, 1, 0, 3};
	t_plane p2 = {1, 0, 0, -2};
	t_plane p3 = {0, 1, 0, -3};
	t_plane p4 = {1, 0, 0, 2};
	
	if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p1, &result) && result.z >= 0 && result.z < 1)
				return (0xffffff);
			else if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p2, &result) && result.z >= 0 && result.z < 1)
				return (0xffffff);
			else if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p3, &result) && result.z >= 0 && result.z < 1)
				return (0xffffff);
			else if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), ray), p4, &result) && result.z >= 0 && result.z < 1)
				return (0xffffff);
			else
				return (0x000000);
	return (0xffffff);
}

void	algo(t_param *p)
{
	t_vec ray;
	int		i;
	int		j;

	j = -1;
	while (++j < p->win->h && (i = -1))
		while (++i < p->win->w)
		{
			ray = vec_rot_z(p->rays[j * p->win->h + i], p->angle);
			ft_pixel_put(p->mlx->img, i, j, ray_casting(ray));
		}
	mlx_put_image_to_window(p->mlx->mlx_ptr, p->mlx->win_ptr, p->mlx->img.ptr, 0, 0);
}

int	hook(int key, t_param* p)
{
	// printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 123)
		p->angle -= 5 * M_PI / 180;
	if (key == 124)
		p->angle += 5 * M_PI / 180;
	algo(p);
	return (0);
}

t_vec	*init_rays(t_param *p)
{
	t_vec	*rays;
	int		size;
	int		i;

	size = p->win->w * p->win->h;
	if (!(rays = malloc(sizeof(t_vec) * size)))
		ft_error_free(p, "Malloc error - Init rays");
	i = -1;
	while (++i < size)
		rays[i] = vec_create(p->win->r_fov_h * (i % p->win->h - p->win->w05), -1, p->win->r_fov_v * (i / p->win->h - p->win->h05));
	return (rays);
}

void	init(t_param *p)
{
	
	if (!(p->mlx = malloc(sizeof(t_mlx))))
		ft_error_free(p, "Malloc error - Mlx struct");
	p->free |= F_MLX;
	if (!(p->mlx->mlx_ptr = mlx_init()))
		ft_error_free(p, "Impossible to start Minilibx");
	p->free |= F_MLX_PTR;
	if (!(p->win = malloc(sizeof(t_win))))
		ft_error_free(p, "Malloc error - Win struct");
	p->free |= F_WIN;
	p->angle = 0;
	p->win->fov_h = FOV * M_PI / 180;
	p->win->fov_h = 2 * tan(p->win->fov_h * 0.5);
	p->parameters = 0;
	// if (mlx_get_screen_size(p->mlx_ptr, &p->w, &p->h))
	// 	ft_error("Minilibx error - Impossible to get screen size");
	// if (WIDTH < 0 || HEIGHT < 0)
	// 	ft_error("Invalid size screen");
	// if (WIDTH < p->w)
	// 	p->w = WIDTH;
	// if (HEIGHT < p->h)
	// 	p->h = HEIGHT;
	// if (!(p->win_ptr = mlx_new_window(p->mlx_ptr, p->w, p->h, "Cub3D")))
	// 	ft_error("Impossible to open a window");
	// ft_create_img(p->mlx_ptr, &p->img, p->w, p->h);
	// p->w05 = p->w * 0.5;
	// p->h05 = p->h * 0.5;
	// p->fov_v = p->fov_h * p->h / p->w;
	// p->fov_v = 2 * tan(p->fov_v * 0.5);
	// p->r_fov_h = p->fov_h / p->w;
	// p->r_fov_v = p->fov_v / p->h;
	// p->rays = init_rays(p);
}

void	verif_defines(void)
{
	if (FOV < 0 || FOV > 360)
		ft_error("Impossible Field Of View");
	if (P_R != 1 || P_NO != 2 || P_SO != 4 || P_WE != 8 || P_EA != 16 	\
			|| P_S != 32 || P_F != 64 || P_C != 128)
		ft_error("Enum t_parameters modified");
	if (F_MLX_PTR != 1 || F_MLX_WIN != 2 || F_MLX_IMG != 4 				\
			|| F_MLX_NO != 8 || F_MLX_SO != 16 || F_MLX_WE != 32 		\
			|| F_MLX_EA != 64 || F_MLX_S != 128 || F_MLX != 256 		\
			|| F_WIN != 512 || F_MAP != 1024 || F_RAYS != 2048 			\
			|| F_CLOSE != 4096)
		ft_error("Enum t_free modified");
}

void	ft_usage(void)
{
	ft_putendl("Usage : ./cub3d map.cub [--save]");
	exit(0);
}

int	main(int ac, char **av)
{
	t_param	*p;

	if (ac == 1)
		ft_usage();
	if (ac > 3)
		ft_error("Wrong number of arguments");
	verif_defines();
	if (!(p = malloc(sizeof(t_param))))
		ft_error("Malloc error - Struct");
	p->free = 0;
	p->fd = -1;
	if (!ft_strstr(av[1], ".cub") || !(p->fd = open(av[1], O_RDONLY)))
		ft_error_free(p, "Invalid map file");
	p->free |= F_CLOSE;
	init(p);
	parsing(p);
	free_fd(p, "Impossible to close map file");
	algo(p);
	mlx_key_hook(p->mlx->win_ptr, hook, p);
	mlx_loop(p->mlx->mlx_ptr);
	free_all(p);
	return (0);
}
