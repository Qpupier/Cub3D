/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:41:13 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:56:22 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!c)
		return ((char *)s + ft_strlen(s));
	if (!*s)
		return (NULL);
	i = ft_strlen(s);
	while (s[--i] != c)
		if (!i)
			return (NULL);
	return ((char *)&s[i]);
}
