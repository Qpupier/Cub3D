/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strings_fps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:58:35 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/31 11:08:11 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_strings_fps_ter(char *strings_fps[])
{
	strings_fps[48] = "FPS : 49";
	strings_fps[49] = "FPS : 50";
	strings_fps[50] = "FPS : 51";
	strings_fps[51] = "FPS : 52";
	strings_fps[52] = "FPS : 53";
	strings_fps[53] = "FPS : 54";
	strings_fps[54] = "FPS : 55";
	strings_fps[55] = "FPS : 56";
	strings_fps[56] = "FPS : 57";
	strings_fps[57] = "FPS : 58";
	strings_fps[58] = "FPS : 59";
	strings_fps[59] = "FPS : 60 (max)";
}

static void	init_strings_fps_bis(char *strings_fps[])
{
	strings_fps[24] = "FPS : 25";
	strings_fps[25] = "FPS : 26";
	strings_fps[26] = "FPS : 27";
	strings_fps[27] = "FPS : 28";
	strings_fps[28] = "FPS : 29";
	strings_fps[29] = "FPS : 30";
	strings_fps[30] = "FPS : 31";
	strings_fps[31] = "FPS : 32";
	strings_fps[32] = "FPS : 33";
	strings_fps[33] = "FPS : 34";
	strings_fps[34] = "FPS : 35";
	strings_fps[35] = "FPS : 36";
	strings_fps[36] = "FPS : 37";
	strings_fps[37] = "FPS : 38";
	strings_fps[38] = "FPS : 39";
	strings_fps[39] = "FPS : 40";
	strings_fps[40] = "FPS : 41";
	strings_fps[41] = "FPS : 42 !";
	strings_fps[42] = "FPS : 43";
	strings_fps[43] = "FPS : 44";
	strings_fps[44] = "FPS : 45";
	strings_fps[45] = "FPS : 46";
	strings_fps[46] = "FPS : 47";
	strings_fps[47] = "FPS : 48";
	init_strings_fps_ter(strings_fps);
}

void	init_strings_fps(char *strings_fps[])
{
	strings_fps[0] = "FPS : 1";
	strings_fps[1] = "FPS : 2";
	strings_fps[2] = "FPS : 3";
	strings_fps[3] = "FPS : 4";
	strings_fps[4] = "FPS : 5";
	strings_fps[5] = "FPS : 6";
	strings_fps[6] = "FPS : 7";
	strings_fps[7] = "FPS : 8";
	strings_fps[8] = "FPS : 9";
	strings_fps[9] = "FPS : 10";
	strings_fps[10] = "FPS : 11";
	strings_fps[11] = "FPS : 12";
	strings_fps[12] = "FPS : 13";
	strings_fps[13] = "FPS : 14";
	strings_fps[14] = "FPS : 15";
	strings_fps[15] = "FPS : 16";
	strings_fps[16] = "FPS : 17";
	strings_fps[17] = "FPS : 18";
	strings_fps[18] = "FPS : 19";
	strings_fps[19] = "FPS : 20";
	strings_fps[20] = "FPS : 21";
	strings_fps[21] = "FPS : 22";
	strings_fps[22] = "FPS : 23";
	strings_fps[23] = "FPS : 24";
	init_strings_fps_bis(strings_fps);
}
