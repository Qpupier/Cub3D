/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:55:35 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/14 18:53:51 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_array_line(t_map *map, char *line, int j)
{
	int		i;
	char	c;

	i = -1;
	while (++i < map->w)
	{
		c = line[i + map->b];
		if (!c)
			break ;
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			map->player = (t_vec){i + 0.5, j + 0.5, Z};
			c = ' ';
		}
		if (c != ' ')
			map->map[j][i] = c - '0';
		else
			map->map[j][i] = 0;
	}
	i--;
	while (++i < map->w)
		map->map[j][i] = 0;
}

void	convert_array(t_param *p, t_parsing *lst)
{
	int			j;
	t_parsing	*tmp;

	tmp = lst;
	while (tmp && !tmp->line)
		tmp = tmp->next;
	p->map->map = malloc(sizeof(int *) * p->map->h);
	if (!p->map->map)
		parsing_lst_error(p, lst, "Malloc error - Map array");
	j = -1;
	while (++j < p->map->h)
	{
		p->map->map[j] = malloc(sizeof(int) * p->map->w);
		if (!p->map->map[j])
			parsing_array_error(p, lst, j, "Malloc error - Line map array");
		convert_array_line(p->map, tmp->line, j);
		tmp = tmp->next;
	}
	p->free |= F_MAP_MAP;
	free_lst(lst);
}

int	map_perim_recur(t_map *map, int x, int y, int *w)
{
	w[y * map->w + x] = 1;
	if (map->map[y][x] == 1)
		return (1);
	if (!x || x == map->w - 1 || !y || y == map->h - 1)
		return (0);
	if (!w[(y - 1) *map->w + x - 1] && !map_perim_recur(map, x - 1, y - 1, w))
		return (0);
	if (!w[(y - 1) *map->w + x] && !map_perim_recur(map, x, y - 1, w))
		return (0);
	if (!w[(y - 1) *map->w + x + 1] && !map_perim_recur(map, x + 1, y - 1, w))
		return (0);
	if (!w[y * map->w + x - 1] && !map_perim_recur(map, x - 1, y, w))
		return (0);
	if (!w[y * map->w + x + 1] && !map_perim_recur(map, x + 1, y, w))
		return (0);
	if (!w[(y + 1) *map->w + x - 1] && !map_perim_recur(map, x - 1, y + 1, w))
		return (0);
	if (!w[(y + 1) *map->w + x] && !map_perim_recur(map, x, y + 1, w))
		return (0);
	if (!w[(y + 1) *map->w + x + 1] && !map_perim_recur(map, x + 1, y + 1, w))
		return (0);
	return (1);
}

void	check_map(t_param *p)
{
	int	*witness;
	int	i;

	witness = malloc(sizeof(int) * p->map->w * p->map->h);
	if (!witness)
		ft_error_free(p, "Malloc error - Check map witness");
	i = -1;
	while (++i < p->map->w * p->map->h)
		witness[i] = 0;
	if (!map_perim_recur(p->map, p->map->player.x - 0.5,
			p->map->player.y - 0.5, witness))
	{
		free(witness);
		parsing_error(p, "No perimeter map delimiter");
	}
	free(witness);
}

void	parsing(t_param *p)
{
	char		*line;
	int			parameters;
	t_parsing	*map;

	parameters = 0;
	while (!parameters && get_next_line(p->fd, &line) > 0)
	{
		parameters = parsing_parameters(p, line);
		if (!parameters)
			free(line);
	}
	if (p->parameters != 255)
		parsing_line_error(p, line, "Miss parameter(s)");
	verif_parameters(p);
	if (!parameters)
		parsing_line_error(p, line, "No map");
	map = parsing_line_map(p, line);
	verif_map(p, map);
	convert_array(p, map);
	check_map(p);
}
