/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:30:30 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/11 18:03:11 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*new_fd(int fd)
{
	t_gnl	*new;

	new = malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->save = NULL;
	new->next = NULL;
	return (new);
}

static t_gnl	*find_fd(t_gnl *gnl, int fd)
{
	t_gnl	*old;

	if (!gnl)
	{
		gnl = new_fd(fd);
		return (gnl);
	}
	old = gnl;
	if (!old->next && old->fd == fd)
		return (old);
	while (old->next)
	{
		if (old->fd == fd)
			return (old);
		old = old->next;
	}
	old->next = new_fd(fd);
	return (old->next);
}

static int	fill_old(t_gnl *old, int size, char **line)
{
	char	*new;
	int		i;

	if (!old->save)
		return (0);
	i = -1;
	while (++i < size)
		*line[i] = old->save[i];
	*line[i--] = '\0';
	new = malloc(sizeof(char) * (ft_strlen(old->save) - size + 1));
	if (!new)
		return (-1);
	while (old->save[++i])
		new[i - size] = old->save[i];
	new[i - size] = '\0';
	free(old->save);
	old->save = new;
	return (0);
}

static int	search_old(t_gnl *old, char **line)
{
	int	i;
	int	size;

	if (!old)
	{
		*line = NULL;
		return (-1);
	}
	i = -1;
	while (old->save && old->save[++i])
		if (old->save[i] == '\n')
			break ;
	if (i == -1 || !old->save || !old->save[i])
	{
		*line = old->save;
		old->save = NULL;
		return (1);
	}
	size = i - 1;
	*line = malloc(sizeof(char) * (size + 1));
	if (!*line)
		return (-1);
	return (fill_old(old, size, line));
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*old;
	char			*tmp;
	int				result;
	char			*new;
	char			*r;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
	{
		*line = NULL;
		return (-1);
	}
	old = find_fd(gnl, fd);
	result = search_old(old, line);
	if (result == -1)
	{
		*line = NULL;
		return (-1);
	}
	if (!result)
		return (1);
	read(fd, r, BUFF_SIZE);
	new = NULL;
	tmp = ft_strjoin(new, r);
	if (!tmp)
		return (-1);
	free(new);
	return (0);
}
