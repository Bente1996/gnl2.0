/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   gnl.c                                                   :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/14 18:13:47 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/14 19:28:14 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *line)
{
	int i = 0;

	while (line[i])
		i++;
	return (i);
}

int	add_line(char *buf) // check hoeveel we gaan plakken
{
	int	i = 0;

	while (buf[i] != '\n')
		i++;
	return (i);
}

char	*make_line(char *buf, char *line, int index)
{
	while (index)
}

int	gnl(int fd)
{
	char	buf[12];
	int	bytes = 0;
	static char	*line;
	char	*bigger_line;
	int	line_len;
	int	add = 0; // set to 0 when line is send
	static int	index = 0; // set to 0 when fresh read

	line_len = ft_strlen(line);
	if (index == BUFFER_SIZE)
		bytes = read(fd, buf, 12); // read wanneer index bij cap
	add = add_line(buf); // zoveel gaan we toevoegen
	buf += add;
	bigger_line = malloc(sizeof(char) * (add + line_len) + 1);
	line = make_line();
	return (bytes);
}



#include <stdio.h>
#include <fcntl.h>
int	main()
{
	const int		fd = open("file.txt", O_RDONLY);
	char			*line;
	int	bytes = 1;

	while (bytes)
		 bytes = gnl(fd);
	close(fd);
	return (0);
}
