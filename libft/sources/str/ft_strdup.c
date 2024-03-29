/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:29:26 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/05 10:10:03 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	if (!s1)
		return (NULL);
	cpy = ft_strnew(ft_strlen(s1));
	if (!cpy)
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
