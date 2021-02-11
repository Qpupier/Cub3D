/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:29:53 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtrimsplit(char **str, char *n, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (n[i])
	{
		j = 0;
		while (n[i] && n[i] != c)
		{
			i++;
			j++;
		}
		str[k++] = ft_strsub((const char*)n, i - j, j);
		while (n[i] == c)
			i++;
	}
	str[k] = 0;
	return (str);
}
