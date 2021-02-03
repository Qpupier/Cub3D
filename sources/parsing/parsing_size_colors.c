/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_size_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:53:48 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/01 16:31:02 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			parsing_r(t_param *p, char *line, int i)
{
	if (p->parameters & P_R)
		parsing_error(p, line, "Parameter already declared (RANGE)");
	if (!line[i] || line[i] != ' ')
		parsing_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] < '0' || line[i] > '9')
		parsing_error(p, line, "Invalid map parameter");
	p->win->w = ft_atoi(line + i);// A CHECKER
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (!line[i] || line[i] != ' ')
		parsing_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] < '0' || line[i] > '9')
		parsing_error(p, line, "Invalid map parameter");
	p->win->h = ft_atoi(line + i);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i])
		if (line[i++] != ' ')
			parsing_error(p, line, "Invalid map parameter");
	p->parameters |= P_R;
}

static int		parsing_f_c_color(t_param *p, char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] < '0' || line[i] > '9')
		parsing_error(p, line, "Invalid map parameter");
	return (i);
}

static t_rgb	parsing_color(t_param *p, char *line, int i)
{
	t_rgb	color;

	if (!line[i] || line[i] != ' ')
		parsing_error(p, line, "Invalid map parameter");
	i = parsing_f_c_color(p, line, i);
	color.r = ft_atoi(line + i);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (!line[i] || line[i] != ',')
		parsing_error(p, line, "Invalid map parameter");
	i = parsing_f_c_color(p, line, i + 1);
	color.g = ft_atoi(line + i);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (!line[i] || line[i] != ',')
		parsing_error(p, line, "Invalid map parameter");
	i = parsing_f_c_color(p, line, i + 1);
	color.b = ft_atoi(line + i);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i])
		if (line[i++] != ' ')
			parsing_error(p, line, "Invalid map parameter");
	color.a = 0;
	return (color);
}

void			parsing_f(t_param *p, char *line, int i)
{
	t_rgb color;

	if (p->parameters & P_F)
		parsing_error(p, line, "Parameter already declared (FLOOR)");
	color = parsing_color(p, line, i);
	if (color.r < 0 || color.r > 255)
		parsing_error(p, line, "Invalid color r parameter (red) (FLOOR)");
	if (color.g < 0 || color.g > 255)
		parsing_error(p, line, "Invalid color g parameter (green) (FLOOR)");
	if (color.b < 0 || color.b > 255)
		parsing_error(p, line, "Invalid color b parameter (blue) (FLOOR)");
	if (color.a < 0 || color.a > 255)
		parsing_error(p, line, 	\
				"Invalid color a parameter (transparency) (FLOOR)");
	p->mlx->f = rgb_to_hex(color);
	p->parameters |= P_F;
}

void			parsing_c(t_param *p, char *line, int i)
{
	t_rgb color;

	if (p->parameters & P_C)
		parsing_error(p, line, "Parameter already declared (CEIL)");
	color = parsing_color(p, line, i);
	if (color.r < 0 || color.r > 255)
		parsing_error(p, line, "Invalid color r parameter (red) (CEIL)");
	if (color.g < 0 || color.g > 255)
		parsing_error(p, line, "Invalid color g parameter (green) (CEIL)");
	if (color.b < 0 || color.b > 255)
		parsing_error(p, line, "Invalid color b parameter (blue) (CEIL)");
	if (color.a < 0 || color.a > 255)
		parsing_error(p, line, 	\
				"Invalid color a parameter (transparency) (CEIL)");
	p->mlx->c = rgb_to_hex(color);
	p->parameters |= P_C;
}
