/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:01:00 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 16:56:10 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*new;

	if (!s)
		return (NULL);
	str = (char**)malloc(sizeof(*str) * (ft_count_words((char*)s, c) + 1));
	if (!str || !c)
		return (NULL);
	new = ft_strctrim(s, c);
	ft_strtrimsplit(str, new, c);
	free(new);
	return (str);
}
