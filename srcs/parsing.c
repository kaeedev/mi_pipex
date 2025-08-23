/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:08:17 by marvin            #+#    #+#             */
/*   Updated: 2025/08/10 11:08:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int i)
{
	if (i == 0)
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
	else if (i == 1)
		write(2, "Error: Input file does not exist\n", 33);
	else if (i == 2)
		write(2, "Error: Input file is not readable\n", 34);
	else if (i == 3)
		write(2, "Error: Cannot write to output file\n", 35);
	else if (i == 4)
		write(2, "Error: Pipe error\n", 19);
	else if (i == 5)
		write(2, "Error: Cannot open file\n", 24);
	else if (i == 6)
		write(2, "Error: Error with execve\n", 25);
	exit(1);
}

int	validate_args(int argc, char **argv)
{
	(void)argv;
	if (argc >= 5)
		return (1);
	ft_error(0);
	return (0);
}

int	check_files(char *file1, char *file2)
{
	int		fd1;
	int		fd2;

	fd1 = open(file1, O_RDONLY);
	if (fd1 == -1)
		ft_error(1);
	close(fd1);
	fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 == -1)
		ft_error(3);
	close(fd2);
	return (1);
}

char	**parse_command(char *cmd)
{
	if (!cmd)
		return (NULL);
	return (ft_split(cmd, ' '));
}
