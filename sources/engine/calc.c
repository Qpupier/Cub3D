/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:24 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/26 12:36:09 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short int	compare_columns_e(t_map *map, int i)
{
	int	j;

	j = -1;
	while (++j < map->h)
		if (i != map->w && map->map[j][i] && !(i && map->map[j][i - 1]))
			return (1);
	return (0);
}

static short int	compare_columns_w(t_map *map, int i)
{
	int	j;

	j = -1;
	while (++j < map->h)
		if (i && map->map[j][i - 1] && (i == map->w || !map->map[j][i]))
			return (1);
	return (0);
}

static short int	compare_lines_n(t_map *map, int i)
{
	int	j;

	j = -1;
	while (++j < map->w)
		if (i && map->map[i - 1][j] && (i == map->h || !map->map[i][j]))
			return (1);
	return (0);
}

static short int	compare_lines_s(t_map *map, int i)
{
	int	j;

	j = -1;
	while (++j < map->w)
		if (i != map->h && map->map[i][j] && !(i && map->map[i - 1][j]))
			return (1);
	return (0);
}

void	calc(t_param *p)
{
	int	i;

	i = -1;
	while (++i <= p->map->w)
	{
		p->map->p_e[i] = compare_columns_e(p->map, i);
		p->map->p_w[i] = compare_columns_w(p->map, i);
	}
	i = -1;
	while (++i <= p->map->h)
	{
		p->map->p_n[i] = compare_lines_n(p->map, i);
		p->map->p_s[i] = compare_lines_s(p->map, i);
	}
}
