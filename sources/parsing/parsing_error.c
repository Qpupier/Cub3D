/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:20:01 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 15:46:01 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_error(t_param *p, const char *error)
{
	ft_putendl("Error");
	ft_error_free(p, error);
}

void	parsing_line_error_tmp(t_param *p, char *line, char *tmp, const char *error)
{
	free(line);
	free(tmp);
	parsing_error(p, error);
}

void	parsing_line_error(t_param *p, char *line, const char *error)
{
	free(line);
	parsing_error(p, error);
}

void	parsing_line_error_map(t_param *p, char *line, t_parsing *map, \
		const char *error)
{
	free(line);
	parsing_lst_error_map(p, map, error);
}

void	parsing_lst_error_map(t_param *p, t_parsing *map, const char *error)
{
	free_lst_map(map);
	parsing_error(p, error);
}

void	parsing_array_error(t_param *p, t_parsing *map, int nb, 	\
		const char *error)
{
	int	i;

	free_lst_map(map);
	i = -1;
	while (++i < nb)
		free(p->map->map[i]);
	free(p->map->map);
	parsing_error(p, error);
}
