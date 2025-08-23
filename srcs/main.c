/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:43:26 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 10:43:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_pipex_normal(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		num_cmds;
	int		num_pipes;

	num_cmds = argc - 3;
	num_pipes = num_cmds - 1;
	check_files(argv[1], argv[argc - 1]);
	px.argc = argc;
	px.argv = argv;
	px.envp = envp;
	px.pids = NULL;
	px.pipes = NULL;
	px.pipes = allocate_pipes(num_pipes);
	px.pids = malloc(sizeof(pid_t) * num_cmds);
	create_all_pipes(px.pipes, num_pipes);
	create_all_processes(num_cmds, &px);
	close_all_pipes(px.pipes, num_pipes);
	wait_all_processes(px.pids, num_cmds);
	free_pipes(px.pipes, num_pipes);
	free(px.pids);
}

int	main(int argc, char **argv, char **envp)
{
	run_pipex_normal(argc, argv, envp);
	return (0);
}
