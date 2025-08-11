/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:19:05 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 13:19:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int	**setup_here_doc_resources(int argc, pid_t **pids, int here_doc_pipe[2])
{
    int		num_cmds;
    int		num_pipes;
    int		**pipes;
    
    num_cmds = argc - 4;
    num_pipes = num_cmds - 1;
    
    pipes = allocate_pipes(num_pipes);
    *pids = malloc(sizeof(pid_t) * num_cmds);
    if (!*pids)
        ft_error(5);
    
    if (pipe(here_doc_pipe) == -1)
        ft_error(4);
        
    return (pipes);
}

pid_t	create_here_doc_input_process(char *limiter, int here_doc_pipe[2])
{
    pid_t	here_doc_pid;
    
    here_doc_pid = fork();
    if (here_doc_pid == -1)
        ft_error(4);
    if (here_doc_pid == 0)
        handle_here_doc(limiter, here_doc_pipe);
    return (here_doc_pid);
}

void	execute_here_doc_pipeline(pid_t *pids, int argc, char **argv, char **envp, int **pipes, int here_doc_pipe[2])
{
    int	num_cmds;
    int	num_pipes;
    
    num_cmds = argc - 4;
    num_pipes = num_cmds - 1;
    
    create_all_pipes(pipes, num_pipes);
    create_here_doc_processes(pids, num_cmds, argc, argv, envp, pipes, here_doc_pipe);
}

void	cleanup_here_doc_resources(int **pipes, pid_t *pids, int here_doc_pipe[2], pid_t here_doc_pid, int argc)
{
    int	num_pipes;
    
    num_pipes = (argc - 4) - 1;
    
    close(here_doc_pipe[0]);
    close(here_doc_pipe[1]);
    close_all_pipes(pipes, num_pipes);
    
    waitpid(here_doc_pid, NULL, 0);
    wait_all_processes(pids, argc - 4);
    
    free_pipes(pipes, num_pipes);
    free(pids);
}