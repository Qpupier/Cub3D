/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:53:10 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 19:15:53 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (!ft_strstr(av[1], ".cub")) //PRECISER
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
	mlx_do_key_autorepeatoff(p->mlx->mlx_ptr);
	mlx_hook(p->mlx->win_ptr, 2, 0, key_press, p);
	mlx_hook(p->mlx->win_ptr, 3, 0, key_release, p);
	mlx_hook(p->mlx->win_ptr, 17, 0, win_exit, p);
	mlx_loop_hook(p->mlx->mlx_ptr, algo, p);
	mlx_loop(p->mlx->mlx_ptr);
	free_all(p);
	return (0);
}
