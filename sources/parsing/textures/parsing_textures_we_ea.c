/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_we_ea.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:50 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 17:48:19 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parsing_textures_we(t_param *p, char *line, char *tmp, int size)
{
	if (tmp[size - 4] == '.' && tmp[size - 3] == 'x'
		&& tmp[size - 2] == 'p' && tmp[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->we, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (WEST)");
		p->free |= F_MLX_WE;
	}
	else if (tmp[size - 4] == '.' && tmp[size - 3] == 'p'
		&& tmp[size - 2] == 'n' && tmp[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->we, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (WEST)");
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
	parsing_textures_we(p, line, tmp, size);
	p->parameters |= P_WE;
}

static void	parsing_textures_ea(t_param *p, char *line, char *tmp, int size)
{
	if (tmp[size - 4] == '.' && tmp[size - 3] == 'x'
		&& tmp[size - 2] == 'p' && tmp[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->ea, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (EAST)");
		p->free |= F_MLX_EA;
	}
	else if (tmp[size - 4] == '.' && tmp[size - 3] == 'p'
		&& tmp[size - 2] == 'n' && tmp[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->ea, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (EAST)");
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
	parsing_textures_ea(p, line, tmp, size);
	p->parameters |= P_EA;
}
