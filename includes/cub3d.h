/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:52:32 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/11 14:10:50 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h> // A ENLEVER
# include "functions.h"
# include "mlx.h"

# define FOV 60

typedef enum e_free
{
	F_MLX_PTR = 1,
	F_MLX_WIN = 2,
	F_MLX_IMG = 4,
	F_MLX_NO = 8,
	F_MLX_SO = 16,
	F_MLX_WE = 32,
	F_MLX_EA = 64,
	F_MLX_S = 128,
	F_MLX = 256,
	F_WIN = 512,
	F_MAP_MAP = 1024,
	F_MAP = 2048,
	F_RAYS = 4096,
	F_CLOSE = 8192
}t_free;

typedef enum e_parameters
{
	P_R = 1,
	P_NO = 2,
	P_SO = 4,
	P_WE = 8,
	P_EA = 16,
	P_S = 32,
	P_F = 64,
	P_C = 128
}t_parameters;

typedef enum e_cardinal
{
	C_N,
	C_S,
	C_W,
	C_E
}t_cardinal;

#endif
