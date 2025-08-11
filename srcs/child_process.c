/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:59:03 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 11:59:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(char **argv, char **envp, int *pipe_fd)
{
	int		file1;
	char	**cmd_args;
	char	*cmd_path;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		ft_error(5);
	dup2(file1, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(file1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmd_args = parse_command(argv[2]);
	cmd_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_path, cmd_args, envp) == -1)
		ft_error(6);
}

void	child_process2(char **argv, char **envp, int *pipe_fd)
{
	int		file2;
	char	**cmd_args;
	char	*cmd_path;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		ft_error(5);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(file2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmd_args = parse_command(argv[3]);
	cmd_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_path, cmd_args, envp) == -1)
		ft_error(6);
}