/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:53:32 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/26 12:12:38 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short int	choice_move(t_move_buttons card)
{
	if (card == MB_D || card == MB_WSD)
		return (0);
	if (card == MB_SD)
		return (45);
	if (card == MB_S || card == MB_ASD)
		return (90);
	if (card == MB_AS)
		return (135);
	if (card == MB_A || card == MB_WAS)
		return (180);
	if (card == MB_WA)
		return (225);
	if (card == MB_W || card == MB_WAD)
		return (270);
	if (card == MB_WD)
		return (315);
	else
		return (-1);
}

void	move(t_param *p, t_move_buttons card)
{
	int	var;

	var = choice_move(card);
	if (var < 0)
		return ;
	p->jump->jump = 1;
	p->jump->p0 = p->map->player;
	p->jump->t = 0;
	p->jump->phi = p->angle_h + var;
	if (p->jump->phi >= 360)
		p->jump->phi -= 360;
	p->jump->theta = 65;
	p->jump->v0 = 3;
}

static short int	choice_jump(t_move_buttons card, float *v0)
{
	*v0 = 5;
	if (card == MB_D || card == MB_WSD || card == MB_A || card == MB_WAS)
		*v0 = 4;
	if (card == MB_SD || card == MB_S || card == MB_ASD || card == MB_AS)
		*v0 = 3;
	if (card == MB_D || card == MB_WSD)
		return (0);
	if (card == MB_SD)
		return (45);
	if (card == MB_S || card == MB_ASD)
		return (90);
	if (card == MB_AS)
		return (135);
	if (card == MB_A || card == MB_WAS)
		return (180);
	if (card == MB_WA)
		return (225);
	if (card == MB_W || card == MB_WAD)
		return (270);
	if (card == MB_WD)
		return (315);
	return (-1);
}

void	jump(t_param *p, t_move_buttons card)
{
	int	var;

	p->jump->jump = 1;
	p->jump->p0 = p->map->player;
	p->jump->t = 0;
	p->jump->theta = 65;
	var = choice_jump(card, &p->jump->v0);
	if (var < 0)
		p->jump->theta = 0;
	p->jump->phi = p->angle_h + var;
	if (p->jump->phi >= 360)
		p->jump->phi -= 360;
}
