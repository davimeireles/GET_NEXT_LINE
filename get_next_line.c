/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:37:25 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/29 19:25:12 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *buffer_read(int fd, char *buf)
{
	int bytes_read;
	char *buffer_read;

	buffer_read = malloc(BUFFER_SIZE + 1);
	if (!buffer_read)
		return NULL;
	bytes_read = 1;
	while (!ft_check_character(buf, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer_read, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer_read);
			if (buf != NULL)
				free(buf);
			return NULL;
		}
		buffer_read[bytes_read] = '\0';
		ft_strjoin(buffer_read, buf);
	}
	free(buffer_read);
	return (buf);
}

char *ft_check_line(char *buf)
{
	int i;
	int len;
	char *line;

	len = 0;
	i = 0;
	while (buf[len] != '\n' && buf[len] != '\0')
		len++;
	len = i;
	if(buf[i] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return NULL;
	line = ft_parse_line(buf,line,1);
	return (line);
}
char *get_next_line(int fd)
{
	char *line;
	static char *buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = buffer_read(fd, buf);
	if(!buf)
		return (NULL);
	line = ft_check_line(buf);
	return (line);
}
/* int main()
{
	int fd;
	char *buffer = NULL;

	fd = open("test.txt", O_RDONLY);
	buffer = get_next_line(fd);
	close(fd);
} */
