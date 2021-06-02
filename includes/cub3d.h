/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:52:32 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/31 16:06:37 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <pthread.h>
# include <stdio.h> // A ENLEVER
# include <time.h>
# include "macros.h"
# include "structs.h"
# include "functions.h"

# define FOV 60//A verifier
# define G 9.80665//A verifier
# define Z 0.7// A VERIFIER
# define NB_THREADS 8// A VERIFIER
# define LIGHT 0.5
# define DISTANCE_LIGHT 5
# define LIGHT_MIN 0.15
# define SPEED 0.2
# define SCALE 2

#endif
