/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:50 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 16:41:51 by qpupier          ###   ########lyon.fr   */
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

static void	parsing_textures_s(t_param *p, char *line, char *tmp)
{
	if (p->mlx->sprite.wall == 1)
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->sprite.texture, tmp))
		{
			free(tmp);
			parsing_line_error(p, line, "Invalid texture file (SPRITE)");
		}
		p->free |= F_MLX_SPRITE;
	}
	else if (p->mlx->sprite.wall == 2)
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->sprite.texture, tmp))
		{
			free(tmp);
			parsing_line_error(p, line, "Invalid texture file (SPRITE)");
		}
		p->free |= F_MLX_SPRITE;
	}
	else
	{
		free(tmp);
		parsing_line_error(p, line, "Invalid texture file (SPRITE)");
	}
}

void	parsing_s(t_param *p, char *line, int i)
{
	int		size;
	char	*tmp;

	if (p->parameters & P_S)
		parsing_line_error(p, line, "Parameter already declared (SPRITE)");
	if (!line[i] || (line[i] != ' ' && line[i] != '	'))
		parsing_line_error(p, line, "Invalid map parameter (SPRITE)");
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	size = ft_strlen(line);
	if (size < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter (SPRITE)");
	tmp = ft_strtrim(line + i);
	size = ft_strlen(tmp);
	if (size < 4)
		parsing_line_error_tmp(p, line, tmp, "Invalid map parameter (SPRITE)");
	p->mlx->sprite.wall = select_texture(tmp, size);
	if (!p->mlx->sprite.wall)
		p->mlx->sprite.color = parsing_rgb(p, tmp);
	else
		parsing_textures_s(p, line, tmp);
	free(tmp);
	p->parameters |= P_S;
}
