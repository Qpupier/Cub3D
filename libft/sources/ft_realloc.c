/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:26:38 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/24 21:29:46 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *array, size_t new_size)
{
	char	*new_array;

	if (!new_size && array)
	{
		new_array = (char *)malloc(sizeof(char));
		if (!new_array)
			return (NULL);
		ft_memdel(&array);
		return (new_array);
	}
	new_array = (char *)malloc(sizeof(char) * new_size);
	if (!new_array)
		return (NULL);
	if (array)
	{
		ft_memcpy(new_array, array, new_size);
		ft_memdel(&array);
	}
	return (new_array);
}
