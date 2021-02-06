/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:24:54 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 17:38:13 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	img;
	t_mlx_img	no;
	t_mlx_img	so;
	t_mlx_img	we;
	t_mlx_img	ea;
	t_mlx_img	s;
	uint32_t	f;
	uint32_t	c;
}t_mlx;

typedef struct s_win
{
	int		w;
	int		h;
	float	w05;
	float	h05;
	float	fov_h;
	float	fov_v;
	float	r_fov_h;
	float	r_fov_v;
}t_win;

typedef struct s_map
{
	int		w;
	int		h;
	int		b;
	int		dir;
	int		**map;
	t_vec	player;
}t_map;

typedef struct s_param
{
	int		free;
	int		fd;
	t_mlx	*mlx;
	t_win	*win;
	t_map	*map;
	int		parameters;
	t_vec	*rays;
	float	angle;
}t_param;

typedef struct s_parsing
{
	char				*line;
	struct s_parsing	*next;
}t_parsing;

#endif
