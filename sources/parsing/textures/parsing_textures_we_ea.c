/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_we_ea.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:50 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/14 16:26:49 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parsing_textures_we(t_param *p, char *line, char *tmp)
{
	if (p->mlx->walls[C_W].wall == 1)
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_W].texture, tmp))
			parsing_line_error_tmp(p, line, tmp, "Invalid texture file (WEST)");
		p->free |= F_MLX_WE;
	}
	else if (p->mlx->walls[C_W].wall == 2)
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_W].texture, tmp))
			parsing_line_error_tmp(p, line, tmp, "Invalid texture file (WEST)");
		p->free |= F_MLX_WE;
	}
	else
		parsing_line_error_tmp(p, line, tmp, "Invalid texture file (WEST)");
}

void	parsing_we(t_param *p, char *line, int i)
{
	int		size;
	char	*tmp;

	if (p->parameters & P_WE)
		parsing_line_error(p, line, "Parameter already declared (WEST)");
	if (!line[i] || line[i] != 'E' || !line[++i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter (WEST)");
	while (line[i] && line[i] == ' ')
		i++;
	size = ft_strlen(line);
	if (size < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter (WEST)");
	tmp = ft_strtrim(line + i);
	size = ft_strlen(tmp);
	if (size < 4)
		parsing_line_error_tmp(p, line, tmp, "Invalid map parameter (WEST)");
	p->mlx->walls[C_W].wall = select_texture(tmp, size);
	if (!p->mlx->walls[C_W].wall)
		p->mlx->walls[C_W].color = parsing_rgb(p, tmp);
	else
		parsing_textures_we(p, line, tmp);
	free(tmp);
	p->parameters |= P_WE;
}

static void	parsing_textures_ea(t_param *p, char *line, char *tmp)
{
	if (p->mlx->walls[C_E].wall == 1)
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_E].texture, tmp))
			parsing_line_error_tmp(p, line, tmp, "Invalid texture file (EAST)");
		p->free |= F_MLX_EA;
	}
	else if (p->mlx->walls[C_E].wall == 2)
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->walls[C_E].texture, tmp))
			parsing_line_error_tmp(p, line, tmp, "Invalid texture file (EAST)");
		p->free |= F_MLX_EA;
	}
	else
		parsing_line_error_tmp(p, line, tmp, "Invalid texture file (EAST)");
}

void	parsing_ea(t_param *p, char *line, int i)
{
	int		size;
	char	*tmp;

	if (p->parameters & P_EA)
		parsing_line_error(p, line, "Parameter already declared (EAST)");
	if (!line[i] || line[i] != 'A' || !line[++i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter (EAST)");
	while (line[i] && line[i] == ' ')
		i++;
	size = ft_strlen(line);
	if (size < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter (EAST)");
	tmp = ft_strtrim(line + i);
	size = ft_strlen(tmp);
	if (size < 4)
		parsing_line_error_tmp(p, line, tmp, "Invalid map parameter (EAST)");
	p->mlx->walls[C_E].wall = select_texture(tmp, size);
	if (!p->mlx->walls[C_E].wall)
		p->mlx->walls[C_E].color = parsing_rgb(p, tmp);
	else
		parsing_textures_ea(p, line, tmp);
	free(tmp);
	p->parameters |= P_EA;
}
