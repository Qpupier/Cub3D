/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_we_ea.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:50 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/04 14:43:46 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parsing_textures_we(t_param *p, char *line, int size, int i)
{
	if (line[size - 4] == '.' && line[size - 3] == 'x' 			\
			&& line[size - 2] == 'p' && line[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->we, line + i))
			parsing_line_error(p, line, "Invalid texture file (WEST)");
		p->free |= F_MLX_WE;
	}
	else if (line[size - 4] == '.' && line[size - 3] == 'p' 	\
			&& line[size - 2] == 'n' && line[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->we, line + i))
			parsing_line_error(p, line, "Invalid texture file (WEST)");
		p->free |= F_MLX_WE;
	}
	else
		parsing_line_error(p, line, "Invalid texture file (WEST)");
}

void		parsing_we(t_param *p, char *line, int i)
{
	int	size;

	if (p->parameters & P_WE)
		parsing_line_error(p, line, "Parameter already declared (WEST)");
	if (!line[i] || line[i] != 'E' || !line[++i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if ((size = ft_strlen(line)) < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter");
	parsing_textures_we(p, line, size, i);
	p->parameters |= P_WE;
}

static void	parsing_textures_ea(t_param *p, char *line, int size, int i)
{
	if (line[size - 4] == '.' && line[size - 3] == 'x' 			\
			&& line[size - 2] == 'p' && line[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->ea, line + i))
			parsing_line_error(p, line, "Invalid texture file (EAST)");
		p->free |= F_MLX_EA;
	}
	else if (line[size - 4] == '.' && line[size - 3] == 'p' 	\
			&& line[size - 2] == 'n' && line[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->ea, line + i))
			parsing_line_error(p, line, "Invalid texture file (EAST)");
		p->free |= F_MLX_EA;
	}
	else
		parsing_line_error(p, line, "Invalid texture file (EAST)");
}

void		parsing_ea(t_param *p, char *line, int i)
{
	int	size;

	if (p->parameters & P_EA)
		parsing_line_error(p, line, "Parameter already declared (EAST)");
	if (!line[i] || line[i] != 'A' || !line[++i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if ((size = ft_strlen(line)) < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter");
	parsing_textures_ea(p, line, size, i);
	p->parameters |= P_EA;
}
