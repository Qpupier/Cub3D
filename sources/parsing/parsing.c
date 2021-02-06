/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:55:35 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 14:39:48 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verif_map(t_param *p, t_parsing *map)
{
	t_parsing	*tmp;
	int			i;
	int			begin;
	int			empty;
	int			end;

	p->map->dir = -1;
	begin = 1;
	end = 0;
	tmp = map;
	while (tmp)
	{
		empty = 1;
		i = -1;
		while (tmp->line[++i])
		{
			if (tmp->line[i] == '0')
				tmp->line[i] = ' ';
			else if (tmp->line[i] == 'N' || tmp->line[i] == 'S' || tmp->line[i] == 'E' || tmp->line[i] == 'W')
			{
				if (p->map->dir != -1)
					parsing_lst_error(p, map, "Multiple player positions");
				if (tmp->line[i] == 'N')
					p->map->dir = C_N;
				else if (tmp->line[i] == 'S')
					p->map->dir = C_S;
				else if (tmp->line[i] == 'E')
					p->map->dir = C_E;
				else
					p->map->dir = C_W;
			}
			else if (tmp->line[i] == '2')
				;//TO DO (add tab sprite)
			else if (tmp->line[i] != '1' && tmp->line[i] != ' ')
				parsing_lst_error(p, map, "Invalid map character");
			if (tmp->line[i] != ' ')
			{
				begin = 0;
				empty = 0;
			}
		}
		if (empty)
		{
			tmp->line = NULL;
			p->map->h--;
			if (!begin)
				end = 1;
		}
		else if (end)
			parsing_lst_error(p, map, "Invalid map (No perimeter - Empty line)");
		tmp = tmp->next;
	}
	if (p->map->dir == -1)
		parsing_lst_error(p, map, "No player position");
}

void	convert_array_line(t_map *map, char *line, int j)
{
	int		i;
	char	c;

	i = -1;
	while (++i < map->w && (c = line[i + map->b]))
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			map->player = (t_vec){i + 0.5, j + 0.5, 0.5};
			c = ' ';
		}
		map->map[j][i] = c == ' ' ? 0 : c - '0';
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
	if (!(p->map->map = malloc(sizeof(int *) * p->map->h)))
		parsing_lst_error(p, lst, "Malloc error - Map array");
	j = -1;
	while (++j < p->map->h)
	{
		if (!(p->map->map[j] = malloc(sizeof(int) * p->map->w)))
			parsing_array_error(p, lst, j, "Malloc error - Line map array");
		convert_array_line(p->map, tmp->line, j);
		tmp = tmp->next;
	}
	p->free |= F_MAP_MAP;
	free_lst(lst);
}

int		map_perimeter_recursive(t_map *map, int x, int y, int *witness)
{
	witness[y * map->w + x] = 1;
	return (map->map[y][x] == 1 										\
			|| (x && x != map->w - 1 && y && y != map->h - 1 			\
			&& (witness[(y - 1) * map->w + x - 1] 						\
			|| map_perimeter_recursive(map, x - 1, y - 1, witness)) 	\
			&& (witness[(y - 1) * map->w + x] 							\
			|| map_perimeter_recursive(map, x, y - 1, witness)) 		\
			&& (witness[(y - 1) * map->w + x + 1] 						\
			|| map_perimeter_recursive(map, x + 1, y - 1, witness)) 	\
			&& (witness[y * map->w + x - 1] 							\
			|| map_perimeter_recursive(map, x - 1, y, witness)) 		\
			&& (witness[y * map->w + x + 1] 							\
			|| map_perimeter_recursive(map, x + 1, y, witness)) 		\
			&& (witness[(y + 1) * map->w + x - 1] 						\
			|| map_perimeter_recursive(map, x - 1, y + 1, witness)) 	\
			&& (witness[(y + 1) * map->w + x] 							\
			|| map_perimeter_recursive(map, x, y + 1, witness)) 		\
			&& (witness[(y + 1) * map->w + x + 1] 						\
			|| map_perimeter_recursive(map, x + 1, y + 1, witness))));
}

void	check_map(t_param *p)
{
	int	*witness;
	int	i;

	if (!(witness = malloc(sizeof(int) * p->map->w * p->map->h)))
		ft_error_free(p, "Malloc error - Check map witness");
	i = -1;
	while (++i < p->map->w * p->map->h)
		witness[i] = 0;
	if (!map_perimeter_recursive(p->map, p->map->player.x - 0.5, p->map->player.y - 0.5, witness))
		parsing_error(p, "No perimeter map delimiter");
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
	int i, j = -1;
	while (++j < p->map->h && (i = -1))
	{
		while (++i < p->map->w)
			ft_putnbr(p->map->map[j][i]);
		ft_putchar('\n');
	}
	// ft_error("PAUSE ACTUELLE");
}
