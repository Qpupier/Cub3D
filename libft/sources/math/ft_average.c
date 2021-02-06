/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_average.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 11:45:35 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 11:29:45 by qpupier       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

float	ft_average(int nb1, int nb2, float p)
{
	return (nb1 + p * (nb2 - nb1));
}
