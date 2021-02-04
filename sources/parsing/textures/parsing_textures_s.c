/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:50 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/04 11:36:55 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parsing_textures_s(t_param *p, char *line, int size, int i)
{
	if (line[size - 4] == '.' && line[size - 3] == 'x' 			\
			&& line[size - 2] == 'p' && line[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->s, line + i))
			parsing_line_error(p, line, "Invalid texture file (SPRITE)");
		p->free |= F_MLX_S;
	}
	else if (line[size - 4] == '.' && line[size - 3] == 'p' 	\
			&& line[size - 2] == 'n' && line[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->s, line + i))
			parsing_line_error(p, line, "Invalid texture file (SPRITE)");
		p->free |= F_MLX_S;
	}
	else
		parsing_line_error(p, line, "Invalid texture file (SPRITE)");
}

void	parsing_s(t_param *p, char *line, int i)
{
	int	size;

	if (p->parameters & P_S)
		parsing_line_error(p, line, "Parameter already declared (SPRITE)");
	if (!line[i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if ((size = ft_strlen(line)) < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter");
	parsing_textures_s(p, line, size, i);
	p->parameters |= P_S;
}
