/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariorte <mariorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:07:01 by mariorte          #+#    #+#             */
/*   Updated: 2025/01/27 12:13:21 by mariorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_read(int fd)
{
	char	buffer;
	ssize_t	nr_bytes;
	
	nr_bytes = read(fd, buffer, BUFFER_SIZE);
	
}