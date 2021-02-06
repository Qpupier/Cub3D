/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:20:01 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 17:37:25 by qpupier          ###   ########lyon.fr   */
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

void	pars_line_err_tmp(t_param *p, char *l, char *t, const char *error)
{
	free(t);
	parsing_line_error(p, l, error);
}

void	parsing_lst_error(t_param *p, t_parsing *map, const char *error)
{
	free_lst(map);
	parsing_error(p, error);
}

void	pars_arr_err(t_param *p, t_parsing *map, int nb, 	\
		const char *error)
{
	int	i;

	free_lst(map);
	i = -1;
	while (++i < nb)
		free(p->map->map[i]);
	free(p->map->map);
	parsing_error(p, error);
}
