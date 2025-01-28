/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariorte <mariorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:34:03 by mariorte          #+#    #+#             */
/*   Updated: 2025/01/28 12:22:59 by mariorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(int fd)
{
	char	*buffer;
	ssize_t	nr_bytes;
	
	if (BUFFER_SIZE > 0)
	{	
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		nr_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nr_bytes <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nr_bytes] = '\0';
		return (buffer);
	}
	return (NULL);
}

char	*get_scan(char *buffer, char *accu)
{
	int		i;
	char	*line;
	static char *resto

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			line = malloc(i);
			line = ft_strlcpy(line, buffer, i);
			resto = malloc(BUFFER_SIZE - i);
			while ((buffer[i] != '\0'))
			{
				i++;
				resto[i] = buffer[i];
			}
			free(buffer);
			return(line);
		}
		i++;
	}
	line = 0;
	accu = ft_strjoin(accu, buffer);
	free(buffer);
	return(accu);
}
