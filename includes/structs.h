/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:24:54 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/06 17:12:47 by qpupier          ###   ########lyon.fr   */
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
	unsigned long int	time;
	unsigned short int	fps;
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
	int	b;
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

typedef struct s_jump
{
	unsigned short int	jump;
	t_vec				p0;
	t_vec				v0;
	unsigned short int	theta;
	unsigned short int	phi;
}t_jump;

typedef struct s_param
{
	unsigned int		free;
	unsigned short int	fd;
	t_mlx				*mlx;
	t_win				*win;
	t_map				*map;
	unsigned short int	parameters;
	t_vec				*rays;
	t_vec				**rays_theta;
	float				rad;
	float				trigo_cos[360];
	float				trigo_sin[360];
	short int			angle_h;
	short int			angle_v;
	// int				nb_sprites;
	// t_sprite			*sprites;
	unsigned short int	fps;
	t_jump				jump;
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
