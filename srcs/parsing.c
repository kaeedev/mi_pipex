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
	else if (i == 4)
		ft_printf("Error: Pipe error\n");
	else if (i == 5)
		ft_printf("Error: Cannot open file\n");
	else if (i == 6)
		ft_printf("Error: Error with execve\n");
	exit(1);
}

int	validate_args(int argc, char **argv)
{
    // ✅ VERIFICAR QUE ESTA LÍNEA ESTÉ PRIMERA
    if (argc == 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
        return (2);  // Modo here_doc
    
    // Caso normal: mínimo 5 argumentos
    if (argc >= 5)
        return (1);
    
    ft_error(0);
    return (0);
}

int check_files(char *file1, char *file2)
{
    int fd1;
    int fd2;
    
    // Verificar archivo de entrada
    fd1 = open(file1, O_RDONLY);
    if (fd1 == -1)
        ft_error(1);  // No existe o no se puede leer
    close(fd1);
    // Verificar archivo de salida (crear/escribir)
    fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1)
        ft_error(3);  // No se puede crear/escribir
    close(fd2);
    
    return (1);
}

char **parse_command(char *cmd)
{
	if (!cmd)
		return (NULL);
	return (ft_split(cmd, ' '));
}

