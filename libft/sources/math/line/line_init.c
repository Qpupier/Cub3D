/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:18:44 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 18:19:02 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_line	line_init(void)
{
	return ((t_line){(t_line_parameter){0, 0}, (t_line_parameter){0, 0},
		(t_line_parameter){0, 0}});
}
