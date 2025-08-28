/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:00:00 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 10:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(char **argv, char **envp, int *pipefd)
{
	int		file_in;
	char	**cmd_args;
	char	*cmd_path;

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		ft_error(5);
	dup2(file_in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(file_in);
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_args = parse_command(argv[2]);
	cmd_path = find_command_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_split(cmd_args);
		ft_error(6);
	}
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		free(cmd_path);
		free_split(cmd_args);
		ft_error(6);
	}
}

void	child_process2(char **argv, char **envp, int *pipefd)
{
	int		file_out;
	char	**cmd_args;
	char	*cmd_path;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
		ft_error(5);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(file_out);
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_args = parse_command(argv[3]);
	cmd_path = find_command_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_split(cmd_args);
		ft_error(6);
	}
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		free(cmd_path);
		free_split(cmd_args);
		ft_error(6);
	}
}
