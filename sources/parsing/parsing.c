/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:55:35 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/04 16:59:39 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_error(t_param *p, const char *error)
{
	ft_putendl("Error");
	ft_error_free(p, error);
}

void	parsing_line_error(t_param *p, char *line, const char *error)
{
	free(line);
	parsing_error(p, error);
}

void	parsing_lst_error(t_param *p, t_parsing *map, const char *error)
{
	free_lst(map);
	parsing_error(p, error);
}

void	parsing_array_error(t_param *p, t_parsing *map, int nb, const char *error)
{
	int	i;

	free_lst(map);
	i = -1;
	while (++i < nb)
		free(p->map->map[i]);
	free(p->map->map);
	parsing_error(p, error);
}

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

void	convert_array(t_param *p, t_parsing *lst)// TO DO NORME
{
	int			i;
	int			j;
	t_parsing	*tmp;
	char		c;

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
		i = -1;
		while (++i < p->map->w && (c = tmp->line[i + p->map->b]))
		{
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				p->map->player = (t_vec){i + 0.5, j + 0.5, 0.5};
				c = ' ';
			}
			p->map->map[j][i] = c == ' ' ? 0 : c - '0';
		}
		i--;
		while (++i < p->map->w)
			p->map->map[j][i] = 0;
		tmp = tmp->next;
	}
	p->free |= F_MAP_MAP;
	free_lst(lst);
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
	int i, j = -1;
	while (++j < p->map->h && (i = -1))
	{
		while (++i < p->map->w)
			ft_putnbr(p->map->map[j][i]);
		ft_putchar('\n');
	}
	ft_error("PAUSE ACTUELLE");
}
