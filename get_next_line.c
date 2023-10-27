/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:37:25 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/27 20:29:44 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*buffer_read(int fd, char *buf)
{
	int		bytes_read;
	char	*buffer_read;

	buffer_read = malloc(BUFFER_SIZE + 1);
	if(!buffer_read)
		return NULL;
	bytes_read = 1; // initialize variabel to get inside the loop
	while(!ft_check_character(buf,'\n') && ft_check_character(buf, '\0') && bytes_read != 0)
	{
		bytes_read = read(fd,buffer_read,BUFFER_SIZE);
		if(bytes_read < 0)
		{
			free(buffer_read);
			if(buf != NULL)
				free(buf);
			return NULL;
		}
		buffer_read[bytes_read] = '\0';
		ft_strjoin(buffer_read,buf);
	}
	free(buffer_read);
	return (buf);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = buffer_read(fd, buf);
	return (line);
}
/* int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
} */