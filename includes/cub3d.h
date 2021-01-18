/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:52:32 by qpupier           #+#    #+#             */
/*   Updated: 2021/01/18 17:01:00 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"

# define FOV 60
# define WIDTH 500
# define HEIGHT 500

typedef struct	s_param
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	img;
	int			w;
	int			h;
	float		w05;
	float		h05;
	float		fov_h;
	float		fov_v;
	float		r_fov_h;
	float		r_fov_v;
	float		angle;
}				t_param;

#endif
