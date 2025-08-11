/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:56:43 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 12:56:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_first_command(char **argv, int **pipes)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		ft_error(5);
	dup2(file_in, STDIN_FILENO);
	dup2(pipes[0][1], STDOUT_FILENO);
	close(file_in);
}

void	setup_last_command(char **argv, int argc, int **pipes, int cmd_index)
{
	int	file_out;

	file_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
		ft_error(5);
	dup2(pipes[cmd_index - 1][0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(file_out);
}

void	setup_middle_command(int **pipes, int cmd_index)
{
	dup2(pipes[cmd_index - 1][0], STDIN_FILENO);
	dup2(pipes[cmd_index][1], STDOUT_FILENO);
}

void	execute_command(int cmd_index, t_pipex *px)
{
	int		num_cmds;
	char	**cmd_args;
	char	*cmd_path;

	num_cmds = px->argc - 3;
	if (cmd_index == 0)
		setup_first_command(px->argv, px->pipes);
	else if (cmd_index == num_cmds - 1)
		setup_last_command(px->argv, px->argc, px->pipes, cmd_index);
	else
		setup_middle_command(px->pipes, cmd_index);
	close_all_pipes(px->pipes, num_cmds - 1);
	cmd_args = parse_command(px->argv[cmd_index + 2]);
	cmd_path = find_command_path(cmd_args[0], px->envp);
	if (execve(cmd_path, cmd_args, px->envp) == -1)
		ft_error(6);
}
