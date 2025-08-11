/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:27:01 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/11 13:23:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		s ++;
		length ++;
	}
	return (length);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len ++;
	}
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i ++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

void	*ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*gnl_strjoin(char *line, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!line)
	{
		line = malloc(sizeof(char) + 1);
		if (!line)
			return (0);
		line[0] = 0;
	}
	str = malloc(sizeof(char) * gnl_strlen(line) + gnl_strlen(buffer) + 1);
	if (!str)
		return (ft_free(&line));
	i = -1;
	while (line[++i])
		str[i] = line[i];
	c = -1;
	while (buffer[++c])
		str[i + c] = buffer[c];
	str[i + c] = '\0';
	free(line);
	return (str);
}

char	*gnl_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(gnl_strlen(s) + 1);
	if (!copy)
	{
		return (NULL);
	}
	while (s[i])
	{
		copy[i] = s[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}
