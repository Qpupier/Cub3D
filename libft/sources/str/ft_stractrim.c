/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stractrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:18:46 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/05 13:48:17 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stractrim(const char *str, const char c)
{
	char	*new;
	int		i;

	if (!c || !str)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(str) - ft_occur(str, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	if (*str != c)
		new[i] = *str;
	while (*++str)
		if (*str != c)
			new[++i] = *str;
	new[++i] = '\0';
	return (new);
}
