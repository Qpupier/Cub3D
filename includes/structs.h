/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:24:54 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 20:16:49 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

typedef struct s_inter
{
	float	t;
	float	r_w;
	float	r_h;
}t_inter;

typedef struct s_sprite
{
	t_plane				p;
	t_vec				pos;
	t_vec				v2;
	unsigned short int	sprite;
	unsigned int		pixel;
	float				dis;
}t_sprite;

typedef struct s_map
{
	t_cardinal		dir;
	t_sprite		*sprites;
	t_vec			player;
	unsigned int	**map;
	unsigned int	*p_e;
	unsigned int	*p_n;
	unsigned int	*p_s;
	unsigned int	*p_w;
	int				b;
	int				h;
	int				nb_sprites;
	int				w;
}t_map;

typedef struct s_wall
{
	t_mlx_img			texture;
	unsigned short int	wall;
	unsigned int		color;
}t_wall;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_mlx_img			img;
	t_wall				sprite;
	t_wall				walls[6];
	char				*strings_fps[120];
	unsigned short int	fps;
	unsigned int		hook_alpha;
	unsigned int		hook_buttons;
	unsigned long int	time;
}t_mlx;

typedef struct s_newton
{
	t_vec				p0;
	unsigned short int	jump;
	unsigned short int	phi;
	unsigned short int	theta;
	float				t;
	float				v0;
}t_newton;

typedef struct s_win
{
	unsigned short int	h;
	unsigned short int	w;
	float				h05;
	float				w05;
	float				fov_h;
	float				fov_v;
	float				r_fov_h;
	float				r_fov_v;
}t_win;

typedef struct s_param
{
	t_map				*map;
	t_mlx				*mlx;
	t_newton			*jump;
	t_vec				**rays_theta;
	t_vec				*rays;
	t_vec				pre_move[5][360];
	t_win				*win;
	unsigned short int	ceil;
	unsigned short int	fd;
	unsigned short int	fps;
	unsigned short int	gravity;
	unsigned short int	key_ceil;
	unsigned short int	key_gravity;
	unsigned short int	parameters;
	unsigned int		free;
	short int			angle_h;
	short int			angle_v;
	float				trigo_cos[360];
	float				trigo_sin[360];
	float				rad;
}t_param;

typedef struct s_parsing
{
	char				*line;
	struct s_parsing	*next;
}t_parsing;

#endif
