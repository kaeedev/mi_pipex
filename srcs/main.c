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

int	main(int argc, char **argv, char **envp)
{
    int		num_cmds;
    int		num_pipes;
    int		**pipes;
    pid_t	*pids;
    int		validation_result;

    validation_result = validate_args(argc, argv);
    if (validation_result == 2)  // here_doc detectado
        handle_here_doc_mode(argc, argv, envp);
    else  // modo normal
    {
        check_files(argv[1], argv[argc - 1]);
        num_cmds = argc - 3;
        num_pipes = num_cmds - 1;
        pipes = allocate_pipes(num_pipes);
        pids = malloc(sizeof(pid_t) * num_cmds);
        create_all_pipes(pipes, num_pipes);
        create_all_processes(pids, num_cmds, argc, argv, envp, pipes);
        close_all_pipes(pipes, num_pipes);
        wait_all_processes(pids, num_cmds);
        free_pipes(pipes, num_pipes);
        free(pids);
    }
    return (0);
}
