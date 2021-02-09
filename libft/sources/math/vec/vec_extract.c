/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:16:34 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:18:31 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_tvec_from_str(char *str)
{
	char	**data;

	data = ft_strsplit(str, ' ');
	if (!data)
		return (0);
	if (count_dstr(data) != 3 || !str_isnumber(data[0])
		|| !str_isnumber(data[1]) || !str_isnumber(data[2]))
	{
		ft_splitdel(&data);
		return (0);
	}
	ft_splitdel(&data);
	return (1);
}

t_vec	str_to_vec3(const char *str)
{
	char	**data;
	t_vec	v;

	data = ft_strsplit(str, ' ');
	if (!data)
		return ((t_vec){0, 0, 0});
	if (!data[0] || !data[1] || !data[2])
	{
		ft_splitdel(&data);
		return ((t_vec){0, 0, 0});
	}
	v = (t_vec){ft_atof(data[0]), ft_atof(data[1]), ft_atof(data[2])};
	ft_splitdel(&data);
	return (v);
}

int	extract_tvec_from_str(char *str, t_vec *result)
{
	char	**data;

	data = ft_strsplit(str, ' ');
	if (!data)
		return (0);
	if (count_dstr(data) != 3)
	{
		ft_splitdel(&data);
		return (0);
	}
	(*result).x = ft_atof(data[0]);
	(*result).y = ft_atof(data[1]);
	(*result).z = ft_atof(data[2]);
	ft_splitdel(&data);
	return (1);
}
