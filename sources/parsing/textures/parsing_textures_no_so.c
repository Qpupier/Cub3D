/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_no_so.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:50 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 17:48:19 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parsing_textures_no(t_param *p, char *line, char *tmp, int size)
{
	if (tmp[size - 4] == '.' && tmp[size - 3] == 'x'
		&& tmp[size - 2] == 'p' && tmp[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->no, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (NORTH)");
		p->free |= F_MLX_NO;
	}
	else if (tmp[size - 4] == '.' && tmp[size - 3] == 'p'
		&& tmp[size - 2] == 'n' && tmp[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->no, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (NORTH)");
		p->free |= F_MLX_NO;
	}
	else
		parsing_line_error_tmp(p, line, tmp, "Invalid texture file (NORTH)");
	free(tmp);
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
	parsing_textures_no(p, line, tmp, size);
	p->parameters |= P_NO;
}

static void	parsing_textures_so(t_param *p, char *line, char *tmp, int size)
{
	if (tmp[size - 4] == '.' && tmp[size - 3] == 'x'
		&& tmp[size - 2] == 'p' && tmp[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->so, tmp))
			parsing_line_error_tmp(p, line, tmp,
				"Invalid texture file (SOUTH)");
		p->free |= F_MLX_SO;
	}
	else if (tmp[size - 4] == '.' && tmp[size - 3] == 'p'
		&& tmp[size - 2] == 'n' && tmp[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->so, tmp))
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
	parsing_textures_so(p, line, tmp, size);
	p->parameters |= P_SO;
}
