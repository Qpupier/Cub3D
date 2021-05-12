/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:24:54 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/12 18:46:53 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_mlx_img			img;
	t_mlx_img			no;
	t_mlx_img			so;
	t_mlx_img			we;
	t_mlx_img			ea;
	t_mlx_img			s;
	unsigned int		f;
	unsigned int		c;
	unsigned int		hook_alpha;
	unsigned int		hook_buttons;
	unsigned short int	fps;
	unsigned long int	time;
	char				*strings_fps[120];
}t_mlx;

typedef struct s_win
{
	unsigned short int	w;
	unsigned short int	h;
	float				w05;
	float				h05;
	float				fov_h;
	float				fov_v;
	float				r_fov_h;
	float				r_fov_v;
}t_win;

typedef struct s_map
{
	int				w;
	int				h;
	int				b;
	t_cardinal		dir;
	unsigned int	**map;
	unsigned int	*p_n;
	unsigned int	*p_s;
	unsigned int	*p_e;
	unsigned int	*p_w;
	t_vec			player;
}t_map;

// typedef struct s_sprite
// {
// 	t_plane	p;
// }t_sprite;

typedef struct s_newton
{
	t_vec				p0;
	unsigned short int	jump;
	unsigned short int	phi;
	unsigned short int	theta;
	// unsigned long int	t;
	float	t;
	float				v0;
}t_newton;

typedef struct s_param
{
	t_mlx				*mlx;
	t_win				*win;
	t_map				*map;
	t_newton			*jump;
	t_vec				*rays;
	t_vec				**rays_theta;
	unsigned int		free;
	unsigned short int	fd;
	unsigned short int	fps;
	unsigned short int	parameters;
	short int			angle_h;
	short int			angle_v;
	short int			key_ceil;
	short int			ceil;
	float				rad;
	float				trigo_cos[360];
	float				trigo_sin[360];
	// int				nb_sprites;
	// t_sprite			*sprites;
}t_param;

typedef struct s_parsing
{
	char				*line;
	struct s_parsing	*next;
}t_parsing;

typedef struct s_inter
{
	float	t;
	float	r_w;
	float	r_h;
}t_inter;

#endif
