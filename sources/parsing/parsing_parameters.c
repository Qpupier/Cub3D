/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:32:53 by qpupier           #+#    #+#             */
/*   Updated: 2021/06/02 15:50:52 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verif_parameters(t_param *p)
{
	if (p->win->w <= 0 || p->win->h <= 0)
		ft_error_free(p, "Invalid range parameter");
	if (((float)p->win->w / SCALE) != (int)(p->win->w / SCALE) \
			|| ((float)p->win->h / SCALE) != (int)(p->win->h / SCALE))
		ft_error_free(p, "Screen range (R) incmompatible with scale (SCALE)");
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
		parsing_line_error(p, line, "Invalid map parameter");
}

int	parsing_parameters(t_param *p, char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	if (!line[i])
		return (0);
	if (line[i] == '0' || line[i] == '1')
		return (1);
	parsing_parameters_swipe(p, line, i);
	return (0);
}
