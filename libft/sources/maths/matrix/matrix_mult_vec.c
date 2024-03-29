/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 23:24:37 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/08 16:17:02 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	matrix_mult_vec(t_matrix_3_3 mat, t_vec v)
{
	return ((t_vec){mat[0][0] * v.x + mat[0][1] * v.y + mat[0][2] * v.z,
		mat[1][0] * v.x + mat[1][1] * v.y + mat[1][2] * v.z,
		mat[2][0] * v.x + mat[2][1] * v.y + mat[2][2] * v.z});
}
