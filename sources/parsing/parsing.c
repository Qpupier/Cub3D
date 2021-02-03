/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:55:35 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/03 15:37:45 by qpupier          ###   ########lyon.fr   */
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
