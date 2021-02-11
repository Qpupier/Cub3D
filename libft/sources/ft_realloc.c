/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:31:29 by slopez            #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *array, size_t new_size)
{
	char	*new_array;

	if (!new_size && array)
	{
		if (!(new_array = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&array);
		return (new_array);
	}
	if (!(new_array = (char *)malloc(new_size)))
		return (NULL);
	if (array)
	{
		ft_memcpy(new_array, array, new_size);
		ft_memdel(&array);
	}
	return (new_array);
}
