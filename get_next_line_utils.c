/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:37:43 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/27 20:29:01 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

int	ft_check_character(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strjoin(char *buffer_read, char *buf)
{
	int	len;
	int	i;
	int	j;
	char *joined;
	
	len = ft_strlen(buffer_read) + ft_strlen(buf);
	i = 0;
	joined = malloc(sizeof(char) * len + 1);
	if(!joined)
		return (NULL);
	while(buffer_read[i])
	{
		joined[i] = buffer_read[i];
		i++;
	}
	j = 0;
	while (buf[j])
		joined[i++] = buf[j++];
	joined[i] = '\0';
	if (buffer_read != NULL)
		free(buffer_read);
	return (joined);
}
