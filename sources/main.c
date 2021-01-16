/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:53:10 by qpupier           #+#    #+#             */
/*   Updated: 2021/01/16 15:06:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

typedef struct	s_param
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	img;
	int			angle;
}				t_param;


void	algo(t_param *param)
{
	// t_vec vec;
	t_vec result;
	t_plane p1 = {0, 1, 0, 3};
	t_plane p2 = {1, 0, 0, -2};
	t_plane p3 = {0, 1, 0, -3};
	t_plane p4 = {1, 0, 0, 2};

	int	i;
	int	j;
	
	float angle = param->angle*M_PI/180;
	float fov = 60*M_PI/180;
	float fov_h = fov * 500/500;
	fov = 2*tan(fov*0.5);
	fov_h = 2*tan(fov_h*0.5);
	// fov = tan(fov*M_PI/180/2)*2;
	j = -1;
	while (++j < 500)
	{
		// vec = vec_rot_x(vec_create(0, -1, 0), atan(fov/500*(j-500/2)));
		i = -1;
		while (++i < 500)
		{
			// printf("%d -> %f\n", i, 60*M_PI/180/500*(i-500/2));
			// printf("%f\n", 60*M_PI/180/500*(i-500/2));
			// printf("%f\n\n", atan(60*M_PI/180/500*(i-500/2)));
			// t_vec new = vec_rot_z(vec, atan(fov/500*(i-500/2)));
			t_vec new = vec_create(fov_h/500*(i-500/2), -1, fov/500*(j-500/2));
			new = vec_rot_z(new, angle);
			// printf("%d | Vector((%f, %f, %f))\n", i, new.x, new.y, new.z);
			if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), new), p1, &result) && result.z >= 0 && result.z < 1)
			{
				if (j == 225 && (!i || i == 250))
				{
					printf("%d | Vector((%f, %f, %f))\n", i, result.x, result.y, result.z);
					printf("%f\n", vec_norm(result));
				}
				ft_pixel_put(param->img, i, j, 0xffffff);
			}
			else if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), new), p2, &result) && result.z >= 0 && result.z < 1)
				ft_pixel_put(param->img, i, j, 0xffffff);
			else if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), new), p3, &result) && result.z >= 0 && result.z < 1)
				ft_pixel_put(param->img, i, j, 0xffffff);
			else if (inter_line_plane(line_create_point_vec(vec_create(0, 0, 0.5), new), p4, &result) && result.z >= 0 && result.z < 1)
				ft_pixel_put(param->img, i, j, 0xffffff);
			else
				ft_pixel_put(param->img, i, j, 0x000000);
			// printf("%d | %f %f %f\n", i, new.x, new.y, new.z);
		}
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img.ptr, 0, 0);
}

int	hook(int key, t_param* param)
{
	// printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 123)
		param->angle -= 5;
	if (key == 124)
		param->angle += 5;
	algo(param);
	return (0);
}

int	main(int ac, char **av)
{
	t_param		*param;

	if (!(param = malloc(sizeof(t_param))))
		return (-1);
	param->angle = 30;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, 500, 500, "Cub3D");
	ft_create_img(param->mlx_ptr, &param->img, 500, 500);
	algo(param);
	mlx_key_hook(param->win_ptr, hook, param);
	mlx_loop(param->mlx_ptr);
	(void)ac;
	(void)av;
	return (0);
}
