/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:53:10 by qpupier           #+#    #+#             */
/*   Updated: 2021/01/18 17:00:33 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

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
	(void)ray;
	return (0xffffff);
}

void	algo(t_param *p)
{
	t_vec ray;
	int		i;
	int		j;

	j = -1;
	while (++j < p->h && (i = -1))
		while (++i < p->w)
		{
			ray = vec_create(p->r_fov_h * (i - p->w05), -1, 	\
					p->r_fov_v * (j - p->h05));
			ray = vec_rot_z(ray, p->angle);
			ft_pixel_put(p->img, i, j, ray_casting(ray));
		}
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.ptr, 0, 0);
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

void	init(t_param *p)
{
	if (FOV < 0 || FOV > 360)
		ft_error("Impossible Field Of View");
	if (mlx_get_screen_size(p->mlx_ptr, &p->w, &p->h))
		ft_error("Minilibx error - Impossible to get screen size");
	if (WIDTH < 0 || HEIGHT < 0)
		ft_error("Invalid size screen");
	if (WIDTH < p->w)
		p->w = WIDTH;
	if (HEIGHT < p->h)
		p->h = HEIGHT;
	if (!(p->mlx_ptr = mlx_init()))
		ft_error("Impossible to start Minilibx");
	if (!(p->win_ptr = mlx_new_window(p->mlx_ptr, p->w, p->h, "Cub3D")))
		ft_error("Impossible to open a window");
	ft_create_img(p->mlx_ptr, &p->img, p->w, p->h);
	p->w05 = p->w * 0.5;
	p->h05 = p->h * 0.5;
	p->angle = 0;
	p->fov_h = FOV * M_PI / 180;
	p->fov_v = p->fov_h * p->h / p->w;
	p->fov_h = 2 * tan(p->fov_h * 0.5);
	p->fov_v = 2 * tan(p->fov_v * 0.5);
	p->r_fov_h = p->fov_h / p->w;
	p->r_fov_v = p->fov_v / p->h;
}

int	main(int ac, char **av)
{
	t_param		*p;

	if (!(p = malloc(sizeof(t_param))))
		return (-1);
	init(p);
	algo(p);
	mlx_key_hook(p->win_ptr, hook, p);
	mlx_loop(p->mlx_ptr);
	(void)ac;
	(void)av;
	return (0);
}
