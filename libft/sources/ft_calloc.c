/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:30:31 by slopez            #+#    #+#             */
/*   Updated: 2021/01/08 14:36:48 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	s;
	char			*ptr;

	s = nmemb * size;
	if (!(ptr = malloc(s)))
		return (NULL);
	ft_memset(ptr, 0, s);
	return (ptr);
}
