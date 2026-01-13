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
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	line[BUFFER_SIZE];

	while (line[bytes_read] != '\n' && line[bytes_read] != -1)
	{
		bytes_read = read(fd, line, 1);
	}
	return (line);
}

int	main()
{
	FILE	*fd;
	char	line[];
	static size_t	bytes_read = 0;

	fd = fopen(fd, O_RDONLY);
	while (bytes_read)
	{
		line = get_next_line(fd);
		line += bytes_read;
	}
	fd = fclose(fd);
	return (0);
}
