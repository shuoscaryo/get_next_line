/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:04:34 by orudek            #+#    #+#             */
/*   Updated: 2023/04/19 12:22:42 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static char	ft_init(char **buffer, int fd)
{
	if (read(fd, 0, 0) < 0 && *buffer)
	{
		free(*buffer);
		*buffer = 0;
		return (0);
	}
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!*buffer)
	{
		*buffer = malloc(1);
		if (!*buffer)
			return (0);
		**buffer = 0;
	}
	return (1);
}

static char	ft_cut_line(char **buf, char **out_str)
{
	unsigned int	i;
	char			*aux_str;
	unsigned int	buf_len;

	i = 0;
	while ((*buf)[i] != '\n' && (*buf)[i] != '\0')
	i++;
	*out_str = malloc(i + 1 + ((*buf)[i] == '\n'));
	if (!*out_str)
		return (0);
	ft_strlcpy(*out_str, *buf, i + 1 + ((*buf)[i] == '\n'));
	buf_len = ft_strlen(*buf) - i + ((*buf)[i] == '\0');
	aux_str = malloc(buf_len);
	if (!aux_str)
	{
		free(*out_str);
		return (0);
	}
	ft_strlcpy(aux_str, &(*buf)[i + 1], buf_len);
	free(*buf);
	*buf = aux_str;
	return (1);
}

char	ft_get_buffer(char **buffer, int fd)
{
	char	*aux;
	int		read_bytes;

	aux = malloc(BUFFER_SIZE);
	if (!aux)
		return (0);
	read_bytes = 1;
	while (read_bytes && !ft_strchr(*buffer, '\n'))
	{
		read_bytes = read(fd, aux, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_free(aux));
		if (!ft_strjoin(buffer, aux, read_bytes))
			return (ft_free(aux));
	}
	ft_free(aux);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*out_str;

	if (!ft_init(&buffer[fd], fd))
		return (NULL);
	if (!ft_get_buffer(&buffer[fd], fd))
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (!*buffer[fd] || !ft_cut_line(&buffer[fd], &out_str))
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	return (out_str);
}
