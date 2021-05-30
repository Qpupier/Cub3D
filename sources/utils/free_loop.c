/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:58:16 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 16:43:51 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_param *p)
{
	int	i;

	if (p->free & F_MAP_SPRITES)
		free_one(p, p->map->sprites, F_MAP_SPRITES);
	if (p->free & F_MAP_MAP)
	{
		i = -1;
		while (++i < p->map->h)
			free(p->map->map[i]);
		free_one(p, p->map->map, F_MAP_MAP);
	}
	if (p->free & F_MAP_PN)
		free_one(p, p->map->p_n, F_MAP_PN);
	if (p->free & F_MAP_PS)
		free_one(p, p->map->p_s, F_MAP_PS);
	if (p->free & F_MAP_PE)
		free_one(p, p->map->p_e, F_MAP_PE);
	if (p->free & F_MAP_PW)
		free_one(p, p->map->p_w, F_MAP_PW);
	free_one(p, p->map, F_MAP);
}

void	free_rays_theta(t_param *p)
{
	int	i;

	i = -1;
	while (++i < 360)
		free(p->rays_theta[i]);
	free_one(p, p->rays_theta, F_RAYS_THETA);
}
