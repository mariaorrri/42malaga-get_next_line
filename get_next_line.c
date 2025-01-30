/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariorte <mariorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:34:03 by mariorte          #+#    #+#             */
/*   Updated: 2025/01/30 16:09:06 by mariorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(int fd)
{
	char	*buffer;
	ssize_t	nr_bytes;
	
	if (BUFFER_SIZE > 0 && fd >= 0)
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
char	*ft_found(char *buffer, int i)
{
	char		*line;
	static char *resto = NULL;
	char		*temp;
	
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 1);
	temp = ft_strdup(buffer + i + 1);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(buffer);
	free(resto);
	resto = temp;
	return(line);
}

char	*get_scan(char *buffer)
{
	int			i;
	static char *accu = NULL;
	char		*temp;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (ft_found(buffer, i));
		i++;
	}
	if (!accu)
		temp = ft_strdup(buffer);
	else
		temp = ft_strjoin(accu, buffer);
	if (!temp)
		return (NULL);
	free(buffer);
	free(accu);
	accu = temp;
	return(accu);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_found(NULL, 0);
	if (line)
		return (line);
	buffer = get_read(fd);
	if (!buffer)
		return (NULL);
	get_scan(buffer);
	line = ft_found(NULL, 0);
	return (line);
}
