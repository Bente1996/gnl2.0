/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   get_next_line.c                                         :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/15 18:23:25 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/16 22:44:16 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include "get_next_line.h"

char	*grab_until_nl(char *tmp)
{
	char	*line;
	size_t	line_len;
	size_t	i;

	i = 0;
	line_len = strlen_char(tmp, '\n') + 1;
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	while (i < line_len)
		line[i++] = *tmp++;
	line[i] = '\0';
	return (line);
}

char	*grab_after_nl(char *tmp)
{
	char	*buf;
	size_t	buf_len;
	size_t	tmp_len;
	int	i;

	i = 0;
	tmp_len = strlen_char(tmp, '\0');
	buf_len = tmp_len - (strlen_char(tmp, '\n') + 1);
	if (!buf_len)
		return (NULL);
	buf = malloc(sizeof(char) * (buf_len + 1));
	if (!buf)
		return (NULL);
	buf[buf_len] = '\0';
	while (buf_len--)
		buf[buf_len] = tmp[--tmp_len];
	return (buf);
}

char	*make_line(char **buf, char *line)
{
	char	*tmp;

	tmp = gnl_strjoin(*buf, line);
	if (!tmp)
		return (NULL);
	if (nl_found(tmp))
	{
		line = grab_until_nl(tmp); // knip bij eerste \n
		*buf = grab_after_nl(tmp); // alles na eerste \n
		free(tmp);
	}
	else
	{
		line = tmp;
		*buf = gnl_calloc(sizeof(char), (BUFFER_SIZE + 1));
		tmp = NULL; // niet free want line wijst naar tmp
	}
	return (line);
}

int	ensure_buf(char **buf)
{
	if (!*buf)
		*buf = gnl_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!*buf)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char	*line;
	ssize_t	bytes;

	line = NULL;
	if (ensure_buf(&buf))
		return (NULL);
	if (!*buf)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (!bytes || bytes == -1)
		{
			free(buf);
			return (NULL);
		}
	}
	while (!nl_found(line) && *buf)
	{
		line = make_line(&buf, line);
		if (!line)
			return (NULL);
		if (!nl_found(line))
			bytes = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}
