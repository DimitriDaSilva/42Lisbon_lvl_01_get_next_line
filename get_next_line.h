/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:47:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/17 11:31:37 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_LINE 200000
# define EOF_CHAR '\xbe'

typedef struct	s_buffer
{
	int			fd;
	char		*buf;
}				t_buffer;

typedef struct	s_buffers
{
	t_buffer	*arr;
	int			len;
}				t_buffers;

int				get_next_line(int fd, char **line);
t_buffer		*get_buffer(int fd, t_buffers *buffers);
int				find_buffer(int fd, t_buffers *buffers);
int				get_rest_line(char **line,
							int pos_line,
							t_buffer *buffer,
							t_buffers *buffers);
void			free_buffers(t_buffers *buffers, t_buffer *buffer, char **line);

/*
** utils
*/

void			*ft_realloc(void *ptr, size_t orig_size, size_t new_size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);

#endif
