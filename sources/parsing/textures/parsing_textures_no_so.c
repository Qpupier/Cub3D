/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_no_so.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:50 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/14 16:26:59 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parsing_textures_no(t_param *p, char *line, char *tmp)
{
	if (p->mlx->walls[C_N].wall == 1)
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_N].texture, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (NORTH)");
		p->free |= F_MLX_NO;
	}
	else if (p->mlx->walls[C_N].wall == 2)
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_N].texture, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (NORTH)");
		p->free |= F_MLX_NO;
	}
	else
		parsing_line_error_tmp(p, line, tmp, "Invalid texture file (NORTH)");
}

void	parsing_no(t_param *p, char *line, int i)
{
	int		size;
	char	*tmp;

	if (p->parameters & P_NO)
		parsing_line_error(p, line, "Parameter already declared (NORTH)");
	if (!line[i] || line[i] != 'O' || !line[++i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter (NORTH)");
	while (line[i] && line[i] == ' ')
		i++;
	size = ft_strlen(line);
	if (size < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter (NORTH)");
	tmp = ft_strtrim(line + i);
	size = ft_strlen(tmp);
	if (size < 4)
		parsing_line_error_tmp(p, line, tmp, "Invalid map parameter (NORTH)");
	p->mlx->walls[C_N].wall = select_texture(tmp, size);
	if (!p->mlx->walls[C_N].wall)
		p->mlx->walls[C_N].color = parsing_rgb(p, tmp);
	else
		parsing_textures_no(p, line, tmp);
	free(tmp);
	p->parameters |= P_NO;
}

static void	parsing_textures_so(t_param *p, char *line, char *tmp)
{
	if (p->mlx->walls[C_S].wall == 1)
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_S].texture, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (SOUTH)");
		p->free |= F_MLX_SO;
	}
	else if (p->mlx->walls[C_S].wall == 2)
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_S].texture, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (SOUTH)");
		p->free |= F_MLX_SO;
	}
	else
		parsing_line_error_tmp(p, line, tmp, "Invalid texture file (SOUTH)");
}

void	parsing_so(t_param *p, char *line, int i)
{
	int		size;
	char	*tmp;

	if (p->parameters & P_SO)
		parsing_line_error(p, line, "Parameter already declared (SOUTH)");
	if (!line[i] || line[i] != 'O' || !line[++i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter (SOUTH)");
	while (line[i] && line[i] == ' ')
		i++;
	size = ft_strlen(line);
	if (size < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter (SOUTH)");
	tmp = ft_strtrim(line + i);
	size = ft_strlen(tmp);
	if (size < 4)
		parsing_line_error_tmp(p, line, tmp, "Invalid map parameter (SOUTH)");
	p->mlx->walls[C_S].wall = select_texture(tmp, size);
	if (!p->mlx->walls[C_S].wall)
		p->mlx->walls[C_S].color = parsing_rgb(p, tmp);
	else
		parsing_textures_so(p, line, tmp);
	free(tmp);
	p->parameters |= P_SO;
}
