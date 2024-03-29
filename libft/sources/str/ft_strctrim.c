/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:14:14 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/09 17:07:07 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[j] == c)
		j--;
	if (i > j)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(*new) * (j - i + 2));
	if (!new)
		return (NULL);
	while (i <= j)
		new[k++] = s[i++];
	new[k] = '\0';
	return (new);
}
