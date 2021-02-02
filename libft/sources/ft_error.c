/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:31:07 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/02 16:08:53 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libft.h"

void	ft_error(const char *str)
{
	ft_putendl(str);
	exit(-1);
}
