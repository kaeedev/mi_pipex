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
    
    close(pipe_fd[0]);  // Solo vamos a escribir
    while (1)
    {
        write(STDOUT_FILENO, "> ", 2);  // Prompt
        line = get_next_line(STDIN_FILENO);  // Leer línea
        if (!line)  // EOF (Ctrl+D)
            break;
        if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && 
            line[ft_strlen(limiter)] == '\n')
        {
            free(line);
            break;  // Encontró el limitador
        }
        write(pipe_fd[1], line, ft_strlen(line));  // Escribir al pipe
        free(line);
    }
    close(pipe_fd[1]);
    exit(0);  // Terminar proceso hijo
}

void	handle_here_doc_mode(int argc, char **argv, char **envp)
{
    int		**pipes;
    pid_t	*pids;
    int		here_doc_pipe[2];
    pid_t	here_doc_pid;
    
    pipes = setup_here_doc_resources(argc, &pids, here_doc_pipe);
    here_doc_pid = create_here_doc_input_process(argv[2], here_doc_pipe);
    execute_here_doc_pipeline(pids, argc, argv, envp, pipes, here_doc_pipe);
    cleanup_here_doc_resources(pipes, pids, here_doc_pipe, here_doc_pid, argc);
}

void	create_here_doc_processes(pid_t *pids, int num_cmds, int argc, char **argv, char **envp, int **pipes, int here_doc_pipe[2])
{
    int	i;

    i = 0;
    while (i < num_cmds)
    {
        pids[i] = fork();
        if (pids[i] == -1)
            ft_error(4);
        if (pids[i] == 0)
            execute_here_doc_command(i, argc, argv, envp, pipes, here_doc_pipe);
        i++;
    }
}

void	execute_here_doc_command(int cmd_index, int argc, char **argv, char **envp, int **pipes, int here_doc_pipe[2])
{
    int		num_cmds;
    char	**cmd_args;
    char	*cmd_path;

    num_cmds = argc - 4;
    
    if (cmd_index == 0)
        setup_here_doc_first_command(here_doc_pipe, pipes);
    else if (cmd_index == num_cmds - 1)
        setup_here_doc_last_command(argv, argc, pipes, cmd_index);
    else
        setup_middle_command(pipes, cmd_index);
    
    close(here_doc_pipe[0]);
    close(here_doc_pipe[1]);
    close_all_pipes(pipes, num_cmds - 1);
    
    cmd_args = parse_command(argv[cmd_index + 3]);  // argv[3] = primer comando
    cmd_path = find_command_path(cmd_args[0], envp);
    if (execve(cmd_path, cmd_args, envp) == -1)
        ft_error(6);
}

void	setup_here_doc_first_command(int here_doc_pipe[2], int **pipes)
{
    dup2(here_doc_pipe[0], STDIN_FILENO);   // Lee del here_doc
    dup2(pipes[0][1], STDOUT_FILENO);       // Escribe al primer pipe
}

