/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:23:19 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/11 13:24:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*gnl_strjoin(char *line, char *buffer);
int		get__next(char *line);
char	*get__extra(char *line, char **save);
char	*get__line(char *buffer, int fd, char **save);
char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
void	*ft_free(char **ptr);
char	*gnl_strdup(const char *s);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif