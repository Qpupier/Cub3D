/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_getaocc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:12:22 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/10 15:12:26 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_getaocc(char *str, char c)
{
	unsigned int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (str + i + 1);
	}
	return (NULL);
}
