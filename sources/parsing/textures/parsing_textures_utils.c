/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:23:12 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/14 16:35:35 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned short int	select_texture(char *tmp, int size)
{
	if (tmp[size - 4] == '.' && tmp[size - 3] == 'x' \
			&& tmp[size - 2] == 'p' && tmp[size - 1] == 'm')
		return (1);
	if (tmp[size - 4] == '.' && tmp[size - 3] == 'p' \
			&& tmp[size - 2] == 'n' && tmp[size - 1] == 'g')
		return (2);
	return (0);
}

static int	parsing_color(char *line, int i)
{
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	if (!line[i] || line[i] < '0' || line[i] > '9')
		return (-1);
	return (i);
}

static int	parsing_rgb_r(t_param *p, char *line, int *i)
{
	*i = parsing_color(line, *i);
	if (*i == -1)
		parsing_line_error(p, line, "Invalid map parameter (RGB color)");
	return (ft_atoi(line + *i));
}

static int	parsing_rgb_gb(t_param *p, char *line, int *i)
{
	while (line[*i] && line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	if (!line[*i] || line[*i] != ',')
	{
		printf("%c\n", line[*i-1]);
		parsing_line_error(p, line, "Invalid map parameter (RGB color)");
	}
	*i = parsing_color(line, *i + 1);
	if (*i == -1)
		parsing_line_error(p, line, "Invalid map parameter (RGB color)");
	return (ft_atoi(line + *i));
}

static void	verif_color(t_param *p, char *line, t_rgb color)
{
	if (color.r < 0 || color.r > 255)
		parsing_line_error(p, line, "Invalid color r parameter (red)");
	if (color.g < 0 || color.g > 255)
		parsing_line_error(p, line, "Invalid color g parameter (green)");
	if (color.b < 0 || color.b > 255)
		parsing_line_error(p, line, "Invalid color b parameter (blue)");
	if (color.a < 0 || color.a > 255)
		parsing_line_error(p, line, "Invalid color a parameter (transparency)");
}

unsigned int	parsing_rgb(t_param *p, char *line)
{
	t_rgb	color;
	int		i;

	i = 0;
	color.r = parsing_rgb_r(p, line, &i);
	color.g = parsing_rgb_gb(p, line, &i);
	color.b = parsing_rgb_gb(p, line, &i);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] && line[i] == ',')
	{
		i = parsing_color(line, i + 1);
		if (i == -1)
			parsing_line_error(p, line, "Invalid map parameter (RGB color)");
		color.a = ft_atoi(line + i);
	}
	else
	{
		while (line[i])
			if (line[i] != ' ' && line[i++] != '	')
				parsing_line_error(p, line, \
						"Invalid map parameter (RGB color)");
		color.a = 0;
	}
	verif_color(p, line, color);
	return (rgb_to_hex(color));
}
