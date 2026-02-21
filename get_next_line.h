/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   get_next_line.h                                         :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/13 19:09:04 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/13 19:29:34 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
#  include <limits.h>
#  if BUFFER_SIZE > INT_MAX || BUFFER_SIZE <= 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 4
#  endif
# else
#  define BUFFER_SIZE 4
# endif

#include <stddef.h>

char	*get_next_line(int fd);
size_t	strlen_char(char *str, char c);
char	*gnl_strjoin(char *buf, char *line);
int		nl_found(char *str);
int		ensure_buf(char **buf);
void	*gnl_calloc(size_t nmemb, size_t size);

#endif
