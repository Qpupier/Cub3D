/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:24 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/11 20:28:58 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc(t_param *p)
{
	int	i;

	i = -1;
	while (++i <= p->map->w)
	{
		p->map->p_n[i] = (t_wall){(t_plane){1, 0, 0, -i}};
		p->map->p_s[i] = (t_wall){(t_plane){1, 0, 0, -i}};
	}
	i = -1;
	while (++i <= p->map->h)
	{
		p->map->p_e[i] = (t_wall){(t_plane){0, 1, 0, -i}};
		p->map->p_w[i] = (t_wall){(t_plane){0, 1, 0, -i}};
	}
}
