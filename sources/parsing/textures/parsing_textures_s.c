/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:50 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 17:36:36 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parsing_textures_s(t_param *p, char *line, char *tmp, int size)
{
	if (tmp[size - 4] == '.' && tmp[size - 3] == 'x'
		&& tmp[size - 2] == 'p' && tmp[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->s, tmp))
			pars_line_err_tmp(p, line, tmp,
				"Invalid texture file (SPRITE)");
		p->free |= F_MLX_S;
	}
	else if (tmp[size - 4] == '.' && tmp[size - 3] == 'p'
		&& tmp[size - 2] == 'n' && tmp[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->s, tmp))
			pars_line_err_tmp(p, line, tmp,
				"Invalid texture file (SPRITE)");
		p->free |= F_MLX_S;
	}
	else
		pars_line_err_tmp(p, line, tmp, "Invalid texture file (SPRITE)");
}

void	parsing_s(t_param *p, char *line, int i)
{
	int		size;
	char	*tmp;

	if (p->parameters & P_S)
		parsing_line_error(p, line, "Parameter already declared (SPRITE)");
	if (!line[i] || line[i] != ' ')
		parsing_line_error(p, line, "Invalid map parameter (SPRITE)");
	while (line[i] && line[i] == ' ')
		i++;
	size = ft_strlen(line);
	if (size < 4 || !line[i])
		parsing_line_error(p, line, "Invalid map parameter (SPRITE)");
	tmp = ft_strtrim(line + i);
	size = ft_strlen(tmp);
	if (size < 4)
		pars_line_err_tmp(p, line, tmp, "Invalid map parameter (SPRITE)");
	parsing_textures_s(p, line, tmp, size);
	p->parameters |= P_S;
}
