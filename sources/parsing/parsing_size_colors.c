/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_size_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:53:48 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/14 16:30:07 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_r(t_param *p, char *line, int i)
{
	if (p->parameters & P_R)
		parsing_line_error(p, line, "Parameter already declared (RANGE)");
	if (!line[i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter (RANGE)");
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] < '0' || line[i] > '9')
		parsing_line_error(p, line, "Invalid map parameter (RANGE)");
	p->win->w = ft_atoi(line + i);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (!line[i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter (RANGE)");
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] < '0' || line[i] > '9')
		parsing_line_error(p, line, "Invalid map parameter (RANGE)");
	p->win->h = ft_atoi(line + i);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i])
		if (line[i++] != ' ')
			parsing_line_error(p, line, "Invalid map parameter (RANGE)");
	p->parameters |= P_R;
}

// static int	parsing_f_c_color(t_param *p, char *line, int i)
// {
// 	while (line[i] && line[i] == ' ')
// 		i++;
// 	if (!line[i] || line[i] < '0' || line[i] > '9')
// 		parsing_line_error(p, line, "Invalid map parameter (color)");
// 	return (i);
// }

// static t_rgb	parsing_color(t_param *p, char *line, int i)
// {
// 	t_rgb	color;

// 	if (!line[i] || line[i] != ' ')
// 		parsing_line_error(p, line, "Invalid map parameter (color)");
// 	i = parsing_f_c_color(p, line, i);
// 	color.r = ft_atoi(line + i);
// 	while (line[i] && line[i] >= '0' && line[i] <= '9')
// 		i++;
// 	if (!line[i] || line[i] != ',')
// 		parsing_line_error(p, line, "Invalid map parameter (color)");
// 	i = parsing_f_c_color(p, line, i + 1);
// 	color.g = ft_atoi(line + i);
// 	while (line[i] && line[i] >= '0' && line[i] <= '9')
// 		i++;
// 	if (!line[i] || line[i] != ',')
// 		parsing_line_error(p, line, "Invalid map parameter (color)");
// 	i = parsing_f_c_color(p, line, i + 1);
// 	color.b = ft_atoi(line + i);
// 	while (line[i] && line[i] >= '0' && line[i] <= '9')
// 		i++;
// 	while (line[i])
// 		if (line[i++] != ' ')
// 			parsing_line_error(p, line, "Invalid map parameter (color)");
// 	color.a = 0;
// 	return (color);
// }

// void	parsing_f(t_param *p, char *line, int i)
// {
// 	t_rgb	color;

// 	if (p->parameters & P_F)
// 		parsing_line_error(p, line, "Parameter already declared (FLOOR)");
// 	color = parsing_color(p, line, i);
// 	if (color.r < 0 || color.r > 255)
// 		parsing_line_error(p, line, "Invalid color r parameter (red) (FLOOR)");
// 	if (color.g < 0 || color.g > 255)
// 		parsing_line_error(p, line,
// 			"Invalid color g parameter (green) (FLOOR)");
// 	if (color.b < 0 || color.b > 255)
// 		parsing_line_error(p, line, "Invalid color b parameter (blue) (FLOOR)");
// 	if (color.a < 0 || color.a > 255)
// 		parsing_line_error(p, line,
// 			"Invalid color a parameter (transparency) (FLOOR)");
// 	p->mlx->walls[C_F].color = rgb_to_hex(color);
// 	p->parameters |= P_F;
// }

// void	parsing_c(t_param *p, char *line, int i)
// {
// 	t_rgb	color;

// 	if (p->parameters & P_C)
// 		parsing_line_error(p, line, "Parameter already declared (CEIL)");
// 	color = parsing_color(p, line, i);
// 	if (color.r < 0 || color.r > 255)
// 		parsing_line_error(p, line, "Invalid color r parameter (red) (CEIL)");
// 	if (color.g < 0 || color.g > 255)
// 		parsing_line_error(p, line, "Invalid color g parameter (green) (CEIL)");
// 	if (color.b < 0 || color.b > 255)
// 		parsing_line_error(p, line, "Invalid color b parameter (blue) (CEIL)");
// 	if (color.a < 0 || color.a > 255)
// 		parsing_line_error(p, line,
// 			"Invalid color a parameter (transparency) (CEIL)");
// 	p->mlx->walls[C_C].color = rgb_to_hex(color);
// 	p->parameters |= P_C;
// }

static void	parsing_textures_f(t_param *p, char *line, char *tmp)
{
	if (p->mlx->walls[C_F].wall == 1)
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_F].texture, tmp))
			parsing_line_error_tmp(p, line, tmp, \
					"Invalid texture file (FLOOR)");
		p->free |= F_MLX_F;
	}
	else if (p->mlx->walls[C_F].wall == 2)
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_F].texture, tmp))
			parsing_line_error_tmp(p, line, tmp, \
					"Invalid texture file (FLOOR)");
		p->free |= F_MLX_F;
	}
	else
		parsing_line_error_tmp(p, line, tmp, "Invalid texture file (FLOOR)");
}

void	parsing_f(t_param *p, char *line, int i)
{
	int		size;
	char	*tmp;

	if (p->parameters & P_F)
		parsing_line_error(p, line, "Parameter already declared (FLOOR)");
	if (!line[i] || (line[i] != ' ' && line[i] != '	'))
		parsing_line_error(p, line, "Invalid map parameter (FLOOR)");
	while (line[i] && line[i] == ' ')
		i++;
	size = ft_strlen(line);
	if (size < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter (FLOOR)");
	tmp = ft_strtrim(line + i);
	size = ft_strlen(tmp);
	if (size < 4)
		parsing_line_error_tmp(p, line, tmp, "Invalid map parameter (FLOOR)");
	p->mlx->walls[C_F].wall = select_texture(tmp, size);
	if (!p->mlx->walls[C_F].wall)
		p->mlx->walls[C_F].color = parsing_rgb(p, tmp);
	else
		parsing_textures_f(p, line, tmp);
	free(tmp);
	p->parameters |= P_F;
}

static void	parsing_textures_c(t_param *p, char *line, char *tmp)
{
	if (p->mlx->walls[C_C].wall == 1)
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_C].texture, tmp))
			parsing_line_error_tmp(p, line, tmp, "Invalid texture file (CEIL)");
		p->free |= F_MLX_C;
	}
	else if (p->mlx->walls[C_C].wall == 2)
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_C].texture, tmp))
			parsing_line_error_tmp(p, line, tmp, "Invalid texture file (CEIL)");
		p->free |= F_MLX_C;
	}
	else
		parsing_line_error_tmp(p, line, tmp, "Invalid texture file (CEIL)");
}

void	parsing_c(t_param *p, char *line, int i)
{
	int		size;
	char	*tmp;

	if (p->parameters & P_C)
		parsing_line_error(p, line, "Parameter already declared (CEIL)");
	if (!line[i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter (CEIL)");
	while (line[i] && line[i] == ' ')
		i++;
	size = ft_strlen(line);
	if (size < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter (CEIL)");
	tmp = ft_strtrim(line + i);
	size = ft_strlen(tmp);
	if (size < 4)
		parsing_line_error_tmp(p, line, tmp, "Invalid map parameter (CEIL)");
	p->mlx->walls[C_C].wall = select_texture(tmp, size);
	if (!p->mlx->walls[C_C].wall)
		p->mlx->walls[C_C].color = parsing_rgb(p, tmp);
	else
		parsing_textures_c(p, line, tmp);
	free(tmp);
	p->parameters |= P_C;
}
