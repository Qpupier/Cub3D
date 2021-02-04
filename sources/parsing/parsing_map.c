/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:36:27 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/04 14:45:03 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_lst(t_parsing *map)
{
	if (!map)
		return ;
	free_lst(map->next);
	free(map->line);
	free(map);
	map = NULL;
}

void		lst_append(t_parsing **map, t_param *p, char *line)
{
	t_parsing	*tmp;
	t_parsing	*new;

	if (!(new = malloc(sizeof(t_parsing))))
		parsing_line_error(p, line, "Malloc error - Parsing map list");
	new->line = line;
	new->next = NULL;
	if (!*map)
		(*map) = new;
	else
	{
		tmp = *map;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static void	parsing_map(t_param *p, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '0'))
		i++;
	if (line[i] && i < p->map->b)
		p->map->b = i;
	i = ft_strlen(line);
	while (i > 0 && (line[i - 1] == ' ' || line[i - 1] == '0'))
		i--;
	if (i > p->map->w)
		p->map->w = i;
}

void		parsing_line_read(t_param *p, t_parsing *map)
{
	char	*line;

	while (get_next_line(p->fd, &line) > 0)
	{
		p->map->h++;
		parsing_map(p, line);
		lst_append(&map, p, line);
	}
	free(line);
}

t_parsing	*parsing_line_map(t_param *p, char *line)
{
	int			nb_lines;
	t_parsing	*map;

	nb_lines = 1;
	p->map->b = ft_strlen(line);
	parsing_map(p, line);
	map = NULL;
	lst_append(&map, p, line);
	p->map->h = 1;
	parsing_line_read(p, map);
	p->map->w -= p->map->b;
	if (p->map->w <= 0)
		parsing_lst_error(p, map, "Invalid map");
	return (map);
}
