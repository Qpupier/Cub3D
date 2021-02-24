/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:13:15 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/24 21:13:26 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsearch(char *str, char c)
{
	int	i;

	i = -1;
	if (str)
		while (str[++i])
			if (str[i] == c)
				return (i);
	return (-1);
}
