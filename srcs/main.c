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
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	validate_args(argc, argv);
	check_files(argv[1], argv[4]);
	if (pipe(pipefd) == -1)
		ft_error(4);
	pid1 = fork();
	if (pid1 == -1)
		ft_error(4);
	if (pid1 == 0)
		child_process1(argv, envp, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		ft_error(4);
	if (pid2 == 0)
		child_process2(argv, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
