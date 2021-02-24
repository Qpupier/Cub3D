/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:43:23 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/24 10:32:14 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s || !(new = (char*)malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	ft_strncpy(new, (char *)s + start, len);
	new[len] = '\0';
	return (new);
}
