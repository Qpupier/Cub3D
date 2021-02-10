/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:29:26 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 17:04:33 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	if (!s1)
		return (NULL);
	cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(s1) + 1));
	if (!cpy)
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
