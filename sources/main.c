/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:53:10 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/11 18:37:03 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	hook(int key, t_param *p)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		p->angle -= 5 * M_PI / 180;
	if (key == 124)
		p->angle += 5 * M_PI / 180;
	algo(p);
	return (0);
}

static void	ft_usage(void)
{
	ft_putendl("Usage : ./cub3d map.cub [--save]");
	exit(0);
}

static t_param	*pre_init(int ac, char **av)
{
	t_param	*p;

	if (ac == 1)
		ft_usage();
	if (ac > 3)
		ft_error("Wrong number of arguments");
	verif_defines();
	p = malloc(sizeof(t_param));
	if (!p)
		ft_error("Malloc error - Struct");
	p->free = 0;
	p->fd = -1;
	if (!ft_strstr(av[1], ".cub"))//PRECISER
		ft_error_free(p, "Invalid map file (must be a .cub)");
	p->fd = open(av[1], O_RDONLY);
	if (!p->fd)
		ft_error_free(p, "Invalid map file");
	p->free |= F_CLOSE;
	return (p);
}

int	main(int ac, char **av)
{
	t_param	*p;

	p = pre_init(ac, av);
	init(p);
	parsing(p);
	init_parameters(p);
	free_fd(p, "Impossible to close map file");
	calc(p);
	algo(p);
	mlx_key_hook(p->mlx->win_ptr, hook, p);
	mlx_loop(p->mlx->mlx_ptr);
	free_all(p);
	return (0);
}
