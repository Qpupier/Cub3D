/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:08:09 by qpupier           #+#    #+#             */
/*   Updated: 2021/03/05 14:31:18 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (!size)
		return (NULL);
	new = (void *)malloc(sizeof(*new) * size);
	if (!new)
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
