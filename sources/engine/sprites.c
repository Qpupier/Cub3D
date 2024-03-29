/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:58:21 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/31 12:35:20 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned short int	check_sprite_color(t_param *p, t_vec result, \
		int i, unsigned int *pixel)
{
	float	scale;

	scale = 0.5 - vec_scale_product((t_vec){
			.x = result.x - p->map->sprites[i].pos.x,
			.y = result.y - p->map->sprites[i].pos.y,
			.z = 0
		}, p->map->sprites[i].v2);
	if (scale >= 0 && scale < 1)
	{
		*pixel = ft_get_pixel(p->mlx->sprite.texture, \
				scale * p->mlx->sprite.texture.w, \
				(1 - result.z + (int)result.z) * p->mlx->sprite.texture.h);
		if (!(*pixel >> 24))
			return (1);
	}
	return (0);
}

float	check_sprites(t_param *p, float ref, t_vec ray, unsigned int *pixel)
{
	t_vec	result;
	int		i;
	float	t;
	float	tmp;

	i = -1;
	while (++i < p->map->nb_sprites && p->map->sprites[i].sprite \
			&& p->map->sprites[i].dis > 0 \
			&& (ref == -1 || p->map->sprites[i].dis <= ref))
	{
		tmp = p->map->sprites[i].p.a * ray.x + p->map->sprites[i].p.b * ray.y;
		if (!tmp)
			continue ;
		t = -(p->map->sprites[i].p.a * p->map->player.x \
				+ p->map->sprites[i].p.b * p->map->player.y \
				+ p->map->sprites[i].p.d) / tmp;
		if (t <= 0)
			continue ;
		result = vec_add(p->map->player, vec_mult_float(ray, t));
		if (result.z >= 0 && result.z < 1 \
				&& check_sprite_color(p, result, i, pixel))
			return (t);
	}
	return (-1);
}

static t_sprite	create_sprite(t_vec s, t_vec v, t_vec pos, \
		unsigned short int sprite)
{
	return ((t_sprite){
		.p = (t_plane){v.x, v.y, 0, -v.x * s.x - v.y * s.y},
		.pos = pos,
		.v2 = vec_normalize((t_vec){v.y, -v.x, 0}),
		.sprite = sprite,
		.dis = vec_norm(v),
		.pixel = 0x000000
		});
}

static void	sort_sprites(t_map *map)
{
	int			i;
	t_sprite	tmp;

	i = -1;
	while (++i < map->nb_sprites - 1)
	{
		if (map->sprites[i].dis > map->sprites[i + 1].dis)
		{
			tmp = map->sprites[i];
			map->sprites[i] = map->sprites[i + 1];
			map->sprites[i + 1] = tmp;
			sort_sprites(map);
		}
	}
}

void	sprites(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->nb_sprites)
		map->sprites[i] = create_sprite(map->sprites[i].pos, \
				vec_sub(map->sprites[i].pos, map->player), \
				map->sprites[i].pos, map->sprites[i].sprite);
	sort_sprites(map);
}
