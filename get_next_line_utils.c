/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   get_next_line_utils.c                                   :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/16 22:39:54 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/16 22:43:25 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

size_t	strlen_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c)
		i++;
	return (i);
}

char	*gnl_strjoin(char *buf, char *line)
{
	const size_t	tmp_len = strlen_char(buf, '\0') + strlen_char(line, '\0');
	char	*tmp;
	int	i;
	int	line_i;
	int	buf_i;

	i = 0;
	tmp = malloc(sizeof(char) * (tmp_len + 1));
	if (!tmp)
		return (NULL);
	if (line)
	{
		line_i = 0;
		while (line[line_i])
			tmp[i++] = line[line_i++];
	}
	buf_i = 0;
	while (buf[buf_i])
		tmp[i++] = buf[buf_i++];
	tmp[i] = '\0';
	free(line);
	free(buf);
	return (tmp);
}

int	nl_found(char *str)
{
	const char	nl = '\n';

	while(str && *str)
	{
		if (*str == nl)
			return (1);
		str++;
	}
	return (0);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = NULL;
	if (!size)
		return (malloc(0));
	if (SIZE_MAX / size > nmemb)
	{
		ptr = malloc(nmemb * size);
		if (!ptr)
			return (NULL);
		i = 0;
		while (i < nmemb * size)
			((char *)ptr)[i++] = 0;
	}
	return (ptr);
}
