/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:10:32 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 13:10:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_here_doc(char *limiter, int pipe_fd[2])
{
	char	*line;

	close(pipe_fd[0]);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipe_fd[1]);
	exit(0);
}

void	handle_here_doc_mode(int argc, char **argv, char **envp)
{
	t_pipex	px;

	px.argc = argc;
	px.argv = argv;
	px.envp = envp;
	px.pipes = setup_here_doc_resources(argc, &px.pids, px.here_doc_pipe);
	px.here_doc_pid = create_here_doc_input_process(argv[2], px.here_doc_pipe);
	execute_here_doc_pipeline(&px);
	cleanup_here_doc_resources(&px);
}

void	create_here_doc_processes(int num_cmds, t_pipex *px)
{
	int	i;

	i = 0;
	while (i < num_cmds)
	{
		px->pids[i] = fork();
		if (px->pids[i] == -1)
			ft_error(4);
		if (px->pids[i] == 0)
			execute_here_doc_command(i, px);
		i++;
	}
}

void	execute_here_doc_command(int cmd_index, t_pipex *px)
{
	int		num_cmds;
	char	**cmd_args;
	char	*cmd_path;

	num_cmds = px->argc - 4;
	if (cmd_index == 0)
		setup_here_doc_first_command(px->here_doc_pipe, px->pipes);
	else if (cmd_index == num_cmds - 1)
		setup_here_doc_last_command(px->argv, px->argc, px->pipes, cmd_index);
	else
		setup_middle_command(px->pipes, cmd_index);
	close(px->here_doc_pipe[0]);
	close(px->here_doc_pipe[1]);
	close_all_pipes(px->pipes, num_cmds - 1);
	cmd_args = parse_command(px->argv[cmd_index + 3]);
	cmd_path = find_command_path(cmd_args[0], px->envp);
	if (execve(cmd_path, cmd_args, px->envp) == -1)
		ft_error(6);
}

void	setup_here_doc_first_command(int here_doc_pipe[2], int **pipes)
{
	dup2(here_doc_pipe[0], STDIN_FILENO);
	dup2(pipes[0][1], STDOUT_FILENO);
}
