/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariorte <mariorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:26:19 by mariorte          #+#    #+#             */
/*   Updated: 2025/02/03 16:27:07 by mariorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char **resto)
{
	char	*line;
	char	*temp;
	int		i;

	if (!*resto)
		return (NULL);
	i = 0;
	while ((*resto)[i] && (*resto)[i] != '\n')
		i++;
	if ((*resto)[i] == '\n')
		i++;
	line = ft_substr(*resto, 0, i);
	if ((*resto)[i])
	{
		temp = ft_strdup(*resto + i);
		free(*resto);
		*resto = temp;
	}
	else
	{
		free(*resto);
		*resto = NULL;
	}
	return (line);
}

char	*process_buffer(char **resto, char *buffer, int read_bytes)
{
	char	*temp;

	if (read_bytes < 0)
	{
		free(*resto);
		*resto = NULL;
		return (NULL);
	}
	if (read_bytes <= 0 && !*resto)
		return (NULL);
	buffer[read_bytes] = '\0';
	if (!*resto)
		*resto = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(*resto, buffer);
		free(*resto);
		*resto = temp;
	}
	if (ft_strchr(*resto, '\n'))
		return (extract_line(resto));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*resto;
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	line = process_buffer(&resto, buffer, read_bytes);
	while (!line && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		line = process_buffer(&resto, buffer, read_bytes);
	}
	free(buffer);
	if (!line && resto)
		line = extract_line(&resto);
	return (line);
}
