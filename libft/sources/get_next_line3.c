/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:30:30 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/24 21:17:17 by qpupier          ###   ########lyon.fr   */
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

static t_gnl	*find_fd(t_gnl **gnl, int fd)
{
	t_gnl	*old;

	if (!*gnl)
	{
		*gnl = new_fd(fd);
		return (*gnl);
	}
	old = *gnl;
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

static int	join_read(t_gnl *gnl, char **line)
{
	char	*str;
	int		ret;
	char	*tmp;

	str = ft_strnew(BUFF_SIZE);
	ret = read(gnl->fd, str, BUFF_SIZE);
	tmp = gnl->save;
	gnl->save = ft_strjoin(gnl->save, str);
	free(tmp);
	free(str);
	if (ret <= 0)
	{
		*line = gnl->save;
		gnl->save = NULL;
		return (ret);
	}
	return (1);
}

int	recursive(t_gnl *gnl, char **line)
{
	int		i;
	char	*tmp;
	int		result;

	i = ft_strsearch(gnl->save, '\n');
	if (i != -1)
	{
		*line = ft_strnew(BUFF_SIZE);
		*line = ft_strncpy(*line, gnl->save, i);
		tmp = ft_strdup(gnl->save + i + 1);
		free(gnl->save);
		gnl->save = tmp;
		return (1);
	}
	result = join_read(gnl, line);
	if (result <= 0)
		return (result);
	return (recursive(gnl, line));
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*file;

	*line = NULL;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	file = find_fd(&gnl, fd);
	if (!file)
		return (-1);
	return (recursive(file, line));
}
