/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:01:54 by qpupier           #+#    #+#             */
/*   Updated: 2021/06/02 15:30:32 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "libft.h"

typedef enum e_free
{
	F_MLX_PTR		= 1 << 0,
	F_MLX_WIN		= 1 << 1,
	F_MLX_IMG		= 1 << 2,
	F_MLX_SPRITE	= 1 << 3,
	F_MLX_NO		= 1 << 4,
	F_MLX_SO		= 1 << 5,
	F_MLX_WE		= 1 << 6,
	F_MLX_EA		= 1 << 7,
	F_MLX_F			= 1 << 8,
	F_MLX_C			= 1 << 9,
	F_MLX			= 1 << 10,
	F_WIN			= 1 << 11,
	F_MAP_SPRITES	= 1 << 12,
	F_MAP_MAP		= 1 << 13,
	F_MAP_PN		= 1 << 14,
	F_MAP_PS		= 1 << 15,
	F_MAP_PE		= 1 << 16,
	F_MAP_PW		= 1 << 17,
	F_MAP			= 1 << 18,
	F_RAYS			= 1 << 19,
	F_RAYS_THETA	= 1 << 20,
	F_NEWTON		= 1 << 21,
	F_CLOSE			= 1 << 22
}t_free;

typedef enum e_parameters
{
	P_R		= 1 << 0,
	P_NO	= 1 << 1,
	P_SO	= 1 << 2,
	P_WE	= 1 << 3,
	P_EA	= 1 << 4,
	P_F		= 1 << 5,
	P_C		= 1 << 6,
	P_S		= 1 << 7
}t_parameters;

typedef enum e_cardinal
{
	C_N,
	C_S,
	C_W,
	C_E,
	C_C,
	C_F
}t_cardinal;

typedef enum e_key
{
	K_A		= 0,
	K_B		= 11,
	K_C		= 8,
	K_D		= 2,
	K_E		= 14,
	K_F		= 3,
	K_G		= 5,
	K_H		= 4,
	K_I		= 34,
	K_J		= 38,
	K_K		= 40,
	K_L		= 37,
	K_M		= 46,
	K_N		= 45,
	K_O		= 31,
	K_P		= 35,
	K_Q		= 12,
	K_R		= 15,
	K_S		= 1,
	K_T		= 17,
	K_U		= 32,
	K_V		= 9,
	K_W		= 13,
	K_X		= 7,
	K_Y		= 16,
	K_Z		= 6,
	K_SPACE	= 49,
	K_ESC	= 53,
	K_LEFT	= 123,
	K_RIGHT	= 124,
	K_DOWN	= 125,
	K_UP	= 126,
	K_CTRL	= 256,
	K_SHIFT	= 257,
	K_CMD	= 259,
	K_ALT	= 261
}t_key;

typedef enum e_hook_alpha
{
	H_A		= 1 << 0,
	H_B		= 1 << 1,
	H_C		= 1 << 2,
	H_D		= 1 << 3,
	H_E		= 1 << 4,
	H_F		= 1 << 5,
	H_G		= 1 << 6,
	H_H		= 1 << 7,
	H_I		= 1 << 8,
	H_J		= 1 << 9,
	H_K		= 1 << 10,
	H_L		= 1 << 11,
	H_M		= 1 << 12,
	H_N		= 1 << 13,
	H_O		= 1 << 14,
	H_P		= 1 << 15,
	H_Q		= 1 << 16,
	H_R		= 1 << 17,
	H_S		= 1 << 18,
	H_T		= 1 << 19,
	H_U		= 1 << 20,
	H_V		= 1 << 21,
	H_W		= 1 << 22,
	H_X		= 1 << 23,
	H_Y		= 1 << 24,
	H_Z		= 1 << 25
}t_hook_alpha;

typedef enum e_hook_buttons
{
	H_SPACE	= 1 << 0,
	H_ESC	= 1 << 1,
	H_LEFT	= 1 << 2,
	H_RIGHT	= 1 << 3,
	H_DOWN	= 1 << 4,
	H_UP	= 1 << 5,
	H_CTRL	= 1 << 6,
	H_SHIFT	= 1 << 7,
	H_CMD	= 1 << 8,
	H_ALT	= 1 << 9
}t_hook_buttons;

typedef enum e_move
{
	M_W	= 1 << 0,
	M_A	= 1 << 1,
	M_S	= 1 << 2,
	M_D	= 1 << 3
}t_move;

typedef enum e_move_buttons
{
	MB_W = 1,
	MB_A,
	MB_WA,
	MB_S,
	MB_WS,
	MB_AS,
	MB_WAS,
	MB_D,
	MB_WD,
	MB_AD,
	MB_WAD,
	MB_SD,
	MB_WSD,
	MB_ASD,
	MB_WASD,
}t_move_buttons;

#endif
