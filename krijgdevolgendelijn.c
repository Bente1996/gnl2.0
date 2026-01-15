/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   krijgdevolgendelijn.c                                   :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/15 16:27:57 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/15 18:20:16 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	**line;
	ssize_t	bytes;

	// while bytes ofzo
	if (!(*line)) // wanneer geen line
	{
		// read in (*line)
		// split line op \n
	}
	if () // als (*line) een \n heeft : haal eerste str weg, return
	if () // als (*line) geen \n heeft: herhaal loop
}

int	get_buf(int fd, char **rest)
{
	char	buf[BUFFER_SIZE];
	ssize_t	bytes;

	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == -1)
		return (1);
	if (bytes == 0)
		return (1);
	*rest = malloc((bytes + 1) * sizeof(char));
	memcpy(rest, buf, bytes);
	(*rest)[bytes] = 0;
	return (0);
}

char	*getting_line(int fd)
{
	static char	*rest;
	char		*return_value;
	char		*tmp;

	if (!rest)
	{
		if (get_buf(fd, &rest))
			return (NULL);
	}
	if (newline_found(rest))
	{
		// split on first \n, put part1 in return_value
		// split on first \n, put part2 in tmp
		// free rest (leaks)
		// put tmp in rest
		// return return_value
	}
	else
	{
		// put rest in return_value
		// set rest to NULL
		// return return_value
	}
}

char	*gnl(int fd)
{
	char	*return_value;
	char	*next;
	char	*tmp;

	return_value = getting_line(fd);
	if (return_value == NULL)
		return (NULL);
	while (!newline_found(return_value))
	{
		next = getting_line(fd);
		// check null
		tmp = strjoin(return_value, next);
		free(return_value);
		free(next);
		return_value = tmp;
		// check null
	}
	return (return_value);
}

char	*getting_line(int fd)
{
	static char	*rest;
	char		buf[BUFFER_SIZE];
	ssize_t	bytes;

	if (!rest) // read wanneer rest == NULL
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0) // clean up
			return (NULL);
		rest = strdup(buf); // stop hele buf in rest
	}
	if () // \n gevonden
	{
		// stop deel t\m \n in line (kan gestuurd worden) // retuurvaarde
		// stop deel achter \n in andere str // gaat naar *rest toe
		// free rest // deze string word niet meer gebruikt
		// stop andere str in rest // voor de volgende call van getting_line()
	}
	else // geen \n gevonden / dus wel rest
	{
		// stop alles van rest in line, nieuwe read
		// zet rest op NULL
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
