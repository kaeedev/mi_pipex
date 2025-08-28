/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:43:00 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/28 10:37:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Includes del sistema
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# include "mi_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

// parsing.c
void	ft_error(int i);
int		validate_args(int argc, char **argv);
int		check_files(char *file1, char *file2);
char	**parse_command(char *cmd);

// path.c
char	*get_env_path(char **envp);
char	*create_path(char *dir, char *cmd);
char	*find_command_path(char *cmd, char **envp);

// utils.c
void	free_split(char **arr);

// child_process.c
void	child_process1(char **argv, char **envp, int *pipefd);
void	child_process2(char **argv, char **envp, int *pipefd);

#endif