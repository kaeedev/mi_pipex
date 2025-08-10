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
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	else if (i == 1)
		ft_printf("Error: Input file does not exist\n");
	else if (i == 2)
		ft_printf("Error: Input file is not readable\n");
	else if (i == 3)
		ft_printf("Error: Cannot write to output file\n");
	exit(1);
}

int	validate_args(int argc, char **argv)
{
	if(argc == 5)
		return(1);
	ft_error(0);
}

int check_files(char *file1, char *file2)
{
	if (access(file1, F_OK) != 0)
		ft_error(1);
	if (access(file1, R_OK) != 0)
		ft_error(2);
	if (access(file2, F_OK) == 0 && access(file2, W_OK) != 0)
		ft_error(3);
	return (1);
}

char **parse_command(char *cmd)
{
	
}

