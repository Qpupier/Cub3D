/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:39:27 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 13:22:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int		ft_strlen_words(const char *s, char c)
{
	int	nb;

	nb = 0;
	while (*s)
		if (*s++ != c)
			nb++;
	return (nb);
}
