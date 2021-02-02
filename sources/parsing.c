/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:55:35 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/02 18:03:54 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_error(t_param *p, char *line, const char *error)
{
	free(line);
	ft_putendl("Error");
	ft_error_free(p, error);
}

static void	parsing_parameters_swipe(t_param *p, char *line, int i)
{
	if (line[i] == 'R')
		parsing_r(p, line, i + 1);
	else if (line[i] == 'N')
		parsing_no(p, line, i + 1);
	else if (line[i] == 'S')
	{
		if (line[++i] && line[i] == 'O')
			parsing_so(p, line, i);
		else
			parsing_s(p, line, i);
	}
	else if (line[i] == 'W')
		parsing_we(p, line, i + 1);
	else if (line[i] == 'E')
		parsing_ea(p, line, i + 1);
	else if (line[i] == 'F')
		parsing_f(p, line, i + 1);
	else if (line[i] == 'C')
		parsing_c(p, line, i + 1);
	else
		parsing_error(p, line, "Invalid map parameter");
}

static int	parsing_parameters(t_param *p, char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (0);
	if (line[i] == '0' || line[i] == '1')
		return (1);
	parsing_parameters_swipe(p, line, i);
	return (0);
}

void		parsing_map(t_param *p, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '0'))
		i++;
	if (i < p->map->b)
		p->map->b = i;
	i = ft_strlen(line);
	while (i > 0 && (line[i - 1] == ' ' || line[i - 1] == '0'))
		i--;
	if (i > p->map->w)
		p->map->w = i;
}

void		lst_append(t_parsing *map, t_param *p, char *line)
{
	t_parsing	*tmp;

	tmp = map;
	while (tmp)
		tmp = tmp->next;
	if (!(tmp = malloc(sizeof(t_parsing))))
		parsing_error(p, line, "Malloc error - Parsing map list");
	tmp->line = line;
	tmp->next = NULL;
}

void		free_lst(t_parsing *map)
{
	if (!map)
		return ;
	free_lst(map->next);
	free(map);
	map = NULL;
}

void		parsing_lst_error(t_param *p, t_parsing *map, const char *error)
{
	free_lst(map);
	free(map);
	ft_putendl("Error");
	ft_error_free(p, error);
}

void		parsing_line_read(t_param *p, t_parsing *map)
{
	char	*line;

	while (get_next_line(p->fd, &line) > 0)
	{
		// ft_putendl(line);
		p->map->h++;
		parsing_map(p, line);
		lst_append(map, p, line);
		free(line);
	}
	free(line);
}

t_parsing	*parsing_line_map(t_param *p, char *line)
{
	int			nb_lines;
	t_parsing	*map;

	nb_lines = 1;
	if (!(p->map = malloc(sizeof(t_map))))
		ft_error_free(p, "Malloc error - Map struct");
	p->map->w = 0;
	p->map->b = ft_strlen(line);
	parsing_map(p, line);
	map = NULL;
	lst_append(map, p, line);
	free(line);
	p->map->h = 1;
	parsing_line_read(p, map);
	p->map->w -= p->map->b;
	if (p->map->w <= 0)
		parsing_lst_error(p, map, "Invalid map");
	return (map);
}

void		parsing(t_param *p)
{
	char		*line;
	int			parameters;
	t_parsing	*map;

	parameters = 0;
	while (!parameters && get_next_line(p->fd, &line) > 0)
	{
		// ft_putendl(line);
		parameters = parsing_parameters(p, line);
		if (!parameters)
			free(line);
	}
	if (p->parameters != 255)
		parsing_error(p, line, "Miss parameter(s)");
	if (!parameters)
		parsing_error(p, line, "No map");
	map = parsing_line_map(p, line);
	// while (map)
	// {
	// 	printf("%s\n", map->line);
	// 	map = map->next;
	// }
	ft_error("PAUSE ACTUELLE");
}
