/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   get_next_line.c                                         :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/13 13:35:18 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/13 13:51:34 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

char	*add_chars(char *buf, char *old_line, int i)
{
	static char	*line;
	int	j = 0;

	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	while (old_line[j])
		j++;
	line = malloc(sizeof(char) * (j + i) + 1);
	if (buf[i] == '\n')
		line[i + j + 1] = '\n';
	line += j;
	j += i;
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		line[i] = buf[i];
		i++;
	}
	if (line[i] != '\n')
		line[i] = '\0';
	line -= j;
	return (line);
}

size_t	line_len(char *line)
{
	size_t	i = 0;

	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*line;
	ssize_t	bytes_read = 1;
	size_t	end = 0;
	static int	start_index = 0;

	while (bytes_read)
	{
		if (start_index == BUFFER_SIZE)
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			start_index = 0;
		}
		if (bytes_read == -1)
			break ;
		line = add_chars(buf, line, start_index);
		end = line_len(line);
		if (line[end])
			return (line);
	}
	return (NULL);
}

#include <stdio.h>
#include <fcntl.h>
int	main()
{
	const int		fd = open("file.txt", O_RDONLY);
	char			*line;

	while (line)
		line = get_next_line(fd);
	close(fd);
	return (0);
}
