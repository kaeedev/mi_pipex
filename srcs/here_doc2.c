/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:19:45 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 13:19:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	setup_here_doc_last_command(char **argv, int argc, int **pipes, int cmd_index)
{
    int	file_out;

    file_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);  // APPEND mode
    if (file_out == -1)
        ft_error(5);
    dup2(pipes[cmd_index - 1][0], STDIN_FILENO);
    dup2(file_out, STDOUT_FILENO);
    close(file_out);
}