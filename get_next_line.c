/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariorte <mariorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:34:03 by mariorte          #+#    #+#             */
/*   Updated: 2025/01/28 10:55:47 by mariorte         ###   ########.fr       */
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

