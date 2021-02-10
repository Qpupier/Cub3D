/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncdelete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:59:14 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:58:17 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strncdelete(char *str, char letter, char replace, int count)
{
	int	i;

	i = -1;
	while (str[++i] && count)
	{
		if (str[i] == letter)
		{
			str[i] = replace;
			count--;
		}
	}
}
