/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariorte <mariorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:34:03 by mariorte          #+#    #+#             */
/*   Updated: 2025/02/17 14:13:14 by mariorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **rest)
{
	char	*line;
	char	*temp;
	int		i;

	if (!*rest)
		return (NULL);
	i = 0;
	while ((*rest)[i] && (*rest)[i] != '\n')
		i++;
	if ((*rest)[i] == '\n')
		i++;
	line = ft_substr(*rest, 0, i);
	if ((*rest)[i])
	{
		temp = ft_strdup(*rest + i);
		free(*rest);
		*rest = temp;
	}
	else
	{
		free(*rest);
		*rest = NULL;
	}
	return (line);
}

char	*process_buffer(char **rest, char *buffer, int read_bytes)
{
	char	*temp;

	if (read_bytes < 0)
	{
		free(*rest);
		*rest = NULL;
		return (NULL);
	}
	if (read_bytes <= 0 && !*rest)
		return (NULL);
	buffer[read_bytes] = '\0';
	if (!*rest)
		*rest = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(*rest, buffer);
		free(*rest);
		*rest = temp;
	}
	if (ft_strchr(*rest, '\n'))
		return (extract_line(rest));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	line = process_buffer(&rest, buffer, read_bytes);
	while (!line && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		line = process_buffer(&rest, buffer, read_bytes);
	}
	free(buffer);
	if (!line && rest)
		line = extract_line(&rest);
	return (line);
}
