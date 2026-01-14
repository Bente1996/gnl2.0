/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   reading.c                                               :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/14 19:28:49 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/14 20:53:07 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*add_line(char *buf, char *old_line, int index)
{
	char	*line;
	int	len = ft_strlen(old_line); // als geen old_line len == 0
	int	add = 0;
	int	i = index;

	while (buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
		add++;
	}
	line = malloc(sizeof(char) * (len + add) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*old_line) // maak strjoin
	{
		line[i] = *old_line;
	}
	while (add)
	{
		line[i] = buf[index];
		index++;
		add--;
	}
	return (line);
}

int	gnl_read(int fd, char **next_part)
{
	static	char	*rest;
	char			*tmp;
	char			buf[BUFFER_SIZE];
	ssize_t			bytes;

	if (!rest)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (1);
		if (bytes == 0)
		{
			*next_part = NULL;
			return (0);
		}
		rest = strdup(buf);
	}
	if (strchr(rest, '\n'))
	{
		*next_part = dupto(rest, strchr(rest, '\n')); // get line until and with
													  // newline
		tmp = strdup(strchr(rest, '\n') + 1); // get the part _after_ the
											  // newline
		free(rest); // free your memory
		rest = tmp; // store the remainder for later use
	}
	else
	{
		*next_part = rest; // no newline, return everything
		rest = NULL; // no remainder
	}
	return (0);
}

// static char *line
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*line; // wordt groter, free wanneer line af is
	static int	fresh;
	static int	read_count;
	static int	index; // waar we zijn in de file
	int	reading = 0;

	if (fresh)
	{
		free(line);
		fresh = 0;
	}
	if (read(fd, buf, BUFFER_SIZE))
	{
		while (!nl_check()) // return line wanneer nl is gevonden
		{
			reading = read_count + 1;
			while (reading) // ga naar juiste plek
			{
				read(fd, buf, BUFFER_SIZE);
				read_count++;
				reading--;
			}
			line = add_line(buf, line, index); // bouw lijn
		}
		fresh = 1;
		return (line);
	}
}

#include <stdio.h>
#include <fcntl.h>
int	main()
{
	const int		fd = open("file.txt", O_RDONLY);
	char			*line;

	line = get_next_line(fd); // eerste line
	close(fd);
	return (0);
}
