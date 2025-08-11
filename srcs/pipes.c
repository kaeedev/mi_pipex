/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:52:53 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 12:52:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int **allocate_pipes(int num_pipes)
{
    int **pipes;
    int i;
    
    pipes = malloc(sizeof(int *) * num_pipes);
    i = 0;
    while (i < num_pipes)
    {
        pipes[i] = malloc(sizeof(int) * 2);
        i++;
    }
    return (pipes);
}

void	create_all_pipes(int **pipes, int num_pipes)
{
    int	i;

    i = 0;
    while (i < num_pipes)
    {
        if (pipe(pipes[i]) == -1)
            ft_error(4);
        i++;
    }
}

void	create_all_processes(pid_t *pids, int num_cmds, int argc, char **argv, char **envp, int **pipes)
{
    int	i;

    i = 0;
    while (i < num_cmds)
    {
        pids[i] = fork();
        if (pids[i] == -1)
            ft_error(4);
        if (pids[i] == 0)
            execute_command(i, argc, argv, envp, pipes);
        i++;
    }
}

void	close_all_pipes(int **pipes, int num_pipes)
{
    int	i;

    i = 0;
    while (i < num_pipes)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
        i++;
    }
}

void	wait_all_processes(pid_t *pids, int num_cmds)
{
    int	i;

    i = 0;
    while (i < num_cmds)
    {
        waitpid(pids[i], NULL, 0);
        i++;
    }
}