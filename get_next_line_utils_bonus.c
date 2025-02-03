/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariorte <mariorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:25:52 by mariorte          #+#    #+#             */
/*   Updated: 2025/02/03 16:26:01 by mariorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len_s1] = s2[i];
			len_s1++;
		}
		str[len_s1] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	char	*p_s1;
	size_t	i;

	p_s1 = (char *)s;
	i = 0;
	d = (char *)malloc(ft_strlen(p_s1) + 1);
	if (d == NULL)
		return (NULL);
	while (p_s1[i] != '\0')
	{
		d[i] = p_s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
