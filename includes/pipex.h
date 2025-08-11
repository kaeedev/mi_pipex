/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:43:00 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/11 13:28:49 by marvin           ###   ########.fr       */
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

# include "mi_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
// Prototipos de funciones
// parsing.c
void    ft_error(int i);
int     validate_args(int argc, char **argv);
int     check_files(char *file1, char *file2);
char    **parse_command(char *cmd);

// path.c
char    *get_env_path(char **envp);
char    *create_path(char *dir, char *cmd);
char    *find_command_path(char *cmd, char **envp);

// child_process.c
void    child_process1(char **argv, char **envp, int *pipe_fd);
void    child_process2(char **argv, char **envp, int *pipe_fd);

// pipes.c / utils.c - Múltiples pipes
int		**allocate_pipes(int num_pipes);
void	free_pipes(int **pipes, int num_pipes);
void	create_all_pipes(int **pipes, int num_pipes);
void	create_all_processes(pid_t *pids, int num_cmds, int argc, char **argv, char **envp, int **pipes);
void	close_all_pipes(int **pipes, int num_pipes);
void	wait_all_processes(pid_t *pids, int num_cmds);
void	execute_command(int cmd_index, int argc, char **argv, char **envp, int **pipes);
void	setup_first_command(char **argv, int **pipes);
void	setup_last_command(char **argv, int argc, int **pipes, int cmd_index);
void	setup_middle_command(int **pipes, int cmd_index);

// here_doc.c - Here_doc functions
void	handle_here_doc_mode(int argc, char **argv, char **envp);
void	handle_here_doc(char *limiter, int pipe_fd[2]);
int		**setup_here_doc_resources(int argc, pid_t **pids, int here_doc_pipe[2]);
pid_t	create_here_doc_input_process(char *limiter, int here_doc_pipe[2]);
void	execute_here_doc_pipeline(pid_t *pids, int argc, char **argv, char **envp, int **pipes, int here_doc_pipe[2]);
void	cleanup_here_doc_resources(int **pipes, pid_t *pids, int here_doc_pipe[2], pid_t here_doc_pid, int argc);
void	create_here_doc_processes(pid_t *pids, int num_cmds, int argc, char **argv, char **envp, int **pipes, int here_doc_pipe[2]);
void	execute_here_doc_command(int cmd_index, int argc, char **argv, char **envp, int **pipes, int here_doc_pipe[2]);
void	setup_here_doc_first_command(int here_doc_pipe[2], int **pipes);
void	setup_here_doc_last_command(char **argv, int argc, int **pipes, int cmd_index);

#endif