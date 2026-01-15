/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   vomit.c                                                 :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/15 18:23:25 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/15 21:06:56 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_strchr(char *buf, char nl)
{
	while (*buf)
	{
		if (*buf == nl)
			return (1);
		buf++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *buf, char *line)
{
	char	*tmp;
	const size_t	tmp_len = ft_strlen(buf) + ft_strlen(line);
	int	i;

	i = 0;
	tmp = malloc(sizeof(char) * (tmp_len + 1));
	if (!tmp)
		return (NULL);
	while (*line)
		tmp[i++] = *line++;
	while (*buf)
		tmp[i++] = *buf++;
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_substr(char *tmp)
{
}

char	*grab_until_newline(char *s);
char	*grab_after_newline(char *s);
char	*grab_pivot_newline(char *s, bool after)
{
	if (after)
	{
		// grab from after newline
	}
	else
	{
		// grab from before newline
	}
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char	*line;
	char	*tmp;
	ssize_t	bytes;

	if (!buf)
		buf = calloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (!*buf)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (!bytes || bytes == -1)
			return (NULL);
	}
	while (*buf)
	{
		if (ft_strchr(buf, '\n')) // als \n
		{
			tmp = ft_strjoin(line, buf);
			free(line);
			free(buf);
			line = ft_substr(tmp); // knip bij eerste \n, return later
			buf = ft_substr(tmp); // alles na eerste \n
			free(tmp);
		}
		else
		{
			tmp = ft_strjoin(line, buf);
			free(line);
			free(buf);
			line = tmp;
			buf = calloc(sizeof(char) * BUFFER_SIZE);
			tmp = NULL;
			// READ
		}
			// buf naar line
			// read in buf
	}
	return (line);
}

int	main()
{
	char	*line;

	const int fd = open("file.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}
