/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:49:46 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 15:44:46 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_char(t_param *p, t_parsing *map, char c)
{
	if (c == '0')
		c = ' ';
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (p->map->dir > -1)
			parsing_lst_error_map(p, map, "Multiple player positions");
		if (c == 'N')
			p->map->dir = C_N;
		else if (c == 'S')
			p->map->dir = C_S;
		else if (c == 'E')
			p->map->dir = C_E;
		else
			p->map->dir = C_W;
	}
	else if (c == '2')
		p->map->nb_sprites++;
	else if (c != '1' && c != ' ')
		parsing_lst_error_map(p, map, "Invalid map character");
}

static short int	check_line(t_param *p, t_parsing *map, t_parsing *tmp, \
		int *begin)
{
	int	empty;
	int	i;

	empty = 1;
	i = -1;
	while (tmp->line[++i])
	{
		check_char(p, map, tmp->line[i]);
		if (tmp->line[i] != ' ')
		{
			*begin = 0;
			empty = 0;
		}
	}
	if (empty)
	{
		tmp->line = NULL;
		p->map->h--;
		if (!*begin)
			return (1);
	}
	else
		return (-1);
	return (0);
}

void	verif_map(t_param *p, t_parsing *map)
{
	t_parsing	*tmp;
	int			begin;
	int			end;
	int			code;

	p->map->dir = -1;
	begin = 1;
	end = 0;
	tmp = map;
	while (tmp)
	{
		code = check_line(p, map, tmp, &begin);
		if (code == 1)
			end = 1;
		else if (code && end)
			parsing_lst_error_map(p, map, \
					"Invalid map (No perimeter - Empty line)");
		tmp = tmp->next;
	}
	if (p->map->dir < 0)
		parsing_lst_error_map(p, map, "No player position");
}
