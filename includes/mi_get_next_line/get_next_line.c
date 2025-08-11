/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:23:15 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/11 13:24:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get__next(char *line)
{
	int	i;

	i = 0;
	if (line != NULL)
	{
		while (line[i] != '\0')
		{
			if (line[i] == '\n')
				return (1);
			i ++;
		}
	}
	return (0);
}

char	*get__extra(char *line, char **save)
{
	int		len;
	char	*temp;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] == '\n')
		len++;
	temp = malloc(len + 1);
	if (!temp)
		return (ft_free(&line));
	gnl_strlcpy(temp, line, len + 1);
	if (line[len] != '\0')
	{
		*save = gnl_strdup(line + len);
		if (!*save)
		{
			free(temp);
			return (ft_free(&line));
		}
	}
	else
		*save = NULL;
	free(line);
	return (temp);
}

char	*get__line(char *buffer, int fd, char **save)
{
	ssize_t	bytes_read;
	char	*line;

	line = *save;
	*save = NULL;
	bytes_read = 1;
	while (bytes_read > 0 && get__next(line) == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_free(&line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = gnl_strjoin(line, buffer);
	}
	if (line == NULL || line[0] == '\0')
		return (ft_free(&line));
	return (get__extra(line, save));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = get__line(buffer, fd, &save);
	free(buffer);
	return (line);
}

/*int	main(void)
{
	int	fd;
	char	*line;

	fd = open("TEXT", O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}*/