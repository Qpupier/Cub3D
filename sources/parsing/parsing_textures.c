/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:50 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/01 16:31:26 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_no(t_param *p, char *line, int i)
{
	int	size;

	if (p->parameters & P_NO)
		parsing_error(p, line, "Parameter already declared (NORTH)");
	if (!line[i] || line[i] != 'O' || !line[++i] || line[i] != ' ')
		parsing_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if ((size = ft_strlen(line)) < 4 || !line[i])
		parsing_error(p, line, "Invalid map parameter");
	if (line[size - 4] == '.' && line[size - 3] == 'x' 			\
			&& line[size - 2] == 'p' && line[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->no, line + i))
			parsing_error(p, line, "Invalid texture file (NORTH)");
	}
	else if (line[size - 4] == '.' && line[size - 3] == 'p' 	\
			&& line[size - 2] == 'n' && line[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->no, line + i))
			parsing_error(p, line, "Invalid texture file (NORTH)");
	}
	else
		parsing_error(p, line, "Invalid texture file (NORTH)");
	p->parameters |= P_NO;
}

void	parsing_so(t_param *p, char *line, int i)
{
	int	size;

	if (p->parameters & P_SO)
		parsing_error(p, line, "Parameter already declared (SOUTH)");
	if (!line[i] || line[i] != 'O' || !line[++i] || line[i] != ' ')
		parsing_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if ((size = ft_strlen(line)) < 4 || !line[i])
		parsing_error(p, line, "Invalid map parameter");
	if (line[size - 4] == '.' && line[size - 3] == 'x' 			\
			&& line[size - 2] == 'p' && line[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->so, line + i))
			parsing_error(p, line, "Invalid texture file (SOUTH)");
	}
	else if (line[size - 4] == '.' && line[size - 3] == 'p' 	\
			&& line[size - 2] == 'n' && line[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->so, line + i))
			parsing_error(p, line, "Invalid texture file (SOUTH)");
	}
	else
		parsing_error(p, line, "Invalid texture file (SOUTH)");
	p->parameters |= P_SO;
}

void	parsing_we(t_param *p, char *line, int i)
{
	int	size;

	if (p->parameters & P_WE)
		parsing_error(p, line, "Parameter already declared (WEST)");
	if (!line[i] || line[i] != 'E' || !line[++i] || line[i] != ' ')
		parsing_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if ((size = ft_strlen(line)) < 4 || !line[i])
		parsing_error(p, line, "Invalid map parameter");
	if (line[size - 4] == '.' && line[size - 3] == 'x' 			\
			&& line[size - 2] == 'p' && line[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->we, line + i))
			parsing_error(p, line, "Invalid texture file (WEST)");
	}
	else if (line[size - 4] == '.' && line[size - 3] == 'p' 	\
			&& line[size - 2] == 'n' && line[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->we, line + i))
			parsing_error(p, line, "Invalid texture file (WEST)");
	}
	else
		parsing_error(p, line, "Invalid texture file (WEST)");
	p->parameters |= P_WE;
}

void	parsing_ea(t_param *p, char *line, int i)
{
	int	size;

	if (p->parameters & P_EA)
		parsing_error(p, line, "Parameter already declared (EAST)");
	if (!line[i] || line[i] != 'A' || !line[++i] || line[i] != ' ')
		parsing_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if ((size = ft_strlen(line)) < 4 || !line[i])
		parsing_error(p, line, "Invalid map parameter");
	if (line[size - 4] == '.' && line[size - 3] == 'x' 			\
			&& line[size - 2] == 'p' && line[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->ea, line + i))
			parsing_error(p, line, "Invalid texture file (EAST)");
	}
	else if (line[size - 4] == '.' && line[size - 3] == 'p' 	\
			&& line[size - 2] == 'n' && line[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->ea, line + i))
			parsing_error(p, line, "Invalid texture file (EAST)");
	}
	else
		parsing_error(p, line, "Invalid texture file (EAST)");
	p->parameters |= P_EA;
}

void	parsing_s(t_param *p, char *line, int i)
{
	int	size;

	if (p->parameters & P_S)
		parsing_error(p, line, "Parameter already declared (SPRITE)");
	if (!line[i] || line[i] != ' ')
		parsing_error(p, line, "Invalid map parameter");
	while (line[i] && line[i] == ' ')
		i++;
	if ((size = ft_strlen(line)) < 4 || !line[i])
		parsing_error(p, line, "Invalid map parameter");
	if (line[size - 4] == '.' && line[size - 3] == 'x' 			\
			&& line[size - 2] == 'p' && line[size - 1] == 'm')
	{
		if (!xpm_to_img(p->mlx->mlx_ptr, &p->mlx->s, line + i))
			parsing_error(p, line, "Invalid texture file (SPRITE)");
	}
	else if (line[size - 4] == '.' && line[size - 3] == 'p' 	\
			&& line[size - 2] == 'n' && line[size - 1] == 'g')
	{
		if (!png_to_img(p->mlx->mlx_ptr, &p->mlx->s, line + i))
			parsing_error(p, line, "Invalid texture file (SPRITE)");
	}
	else
		parsing_error(p, line, "Invalid texture file (SPRITE)");
	p->parameters |= P_S;
}
