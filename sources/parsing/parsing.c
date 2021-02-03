/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:55:35 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/03 17:59:12 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_error(t_param *p, char *line, const char *error)
{
	free(line);
	ft_putendl("Error");
	ft_error_free(p, error);
}

void	parsing_lst_error(t_param *p, t_parsing *map, const char *error)
{
	free_lst(map);
	free(map);
	ft_putendl("Error");
	ft_error_free(p, error);
}

void	verif_map(t_param *p, t_parsing *map)
{
	t_parsing	*tmp;
	int			i;

	tmp = map;
	while (tmp)
	{
		i = -1;
		while (tmp->line[++i])
		{
			if (tmp->line[i] == ' ')
				tmp->line[i] = '0';
			else if (tmp->line[i] == 'N' || tmp->line[i] == 'S' || tmp->line[i] == 'E' || tmp->line[i] == 'W')
				;//TO DO
			else if (tmp->line[i] == '2')
				;//TO DO
			else if (tmp->line[i] != '1')
				parsing_lst_error(p, map, "Invalid map character");
		}
		tmp = tmp->next;
	}
}

void	parsing(t_param *p)
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
	verif_parameters(p);
	if (!parameters)
		parsing_error(p, line, "No map");
	map = parsing_line_map(p, line);
	verif_map(p, map);
	// while (map)
	// {
	// 	printf("%s\n", map->line);
	// 	map = map->next;
	// }
	// ft_error("PAUSE ACTUELLE");
	printf("%d | %d => %d\n", p->map->w, p->map->h, p->map->b);
}
