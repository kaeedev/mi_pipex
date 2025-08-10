/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:43:00 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/10 11:36:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "mi_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h> //para malloc, free y exit
# include <unistd.h> //para read, write y close
# include <fcntl.h> //para open
# include <stdio.h> // Para perror, errores descriptivos

int		validate_args(int argc, char **argv);
void	ft_error(int i);
int		check_files(char *file1, char *file2);
char	**parse_command(char *cmd);
#endif