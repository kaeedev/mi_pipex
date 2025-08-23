/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:43:00 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/23 11:00:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Includes del sistema
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# include "mi_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		**pipes;
	pid_t	*pids;
}	t_pipex;

// Prototipos de funciones
// parsing.c Valida argumentos y archivos
void	ft_error(int i); //Para mensajes de error y terminar el programa
//Comprueba si los argumentos son correctos
int		validate_args(int argc, char **argv);
//Verifica q el archivo de entrada existe y el de salida se puede crear
int		check_files(char *file1, char *file2);
//Divide comandos con un espacio con el split
char	**parse_command(char *cmd);

// path.c Busca el path de los comandos
char	*get_env_path(char **envp); //Busca la variable PATH en el entorno
//Une un directorio y un comando para formar un path completo
char	*create_path(char *dir, char *cmd);
//Busca el path absoluto de un comando usando PATH
char	*find_command_path(char *cmd, char **envp);

// utils.c. Simplemente una funcion de free
//Libera la memoria reservada para los pipes
void	free_pipes(int **pipes, int num_pipes);
//Liberar memoria que reservo en mi ft_split
void	free_split(char **arr);

// commands.c. Configura la entrada/salida de cada comando
//Configura la entrada/salida del primer comando
void	setup_first_command(char **argv, int **pipes);
// Configura la entrada/salida del ultimo comando
void	setup_last_command(char **argv, int argc, int **pipes, int cmd_index);
//Configura la entrada/salida de los comandos intermedios
void	setup_middle_command(int **pipes, int cmd_index);
//Ejecuta el comando correspondiente segun su posicion (primero,
//intermedios, ultimo...)
void	execute_command(int cmd_index, t_pipex *px);

// pipes.c. Crea y gestiona los pipes y procesos
//Reserva memoria para los pipes
int		**allocate_pipes(int num_pipes);
//Crea todos los pipes necesarios
void	create_all_pipes(int **pipes, int num_pipes);
//Cierra todos los extremos de los pipes
void	close_all_pipes(int **pipes, int num_pipes);
//Hace fork de todos los procesos hijos y ejecuta los comandos
void	create_all_processes(int num_cmds, t_pipex *px);
//Espera a que todos los procesos hijos terminen
void	wait_all_processes(pid_t *pids, int num_cmds);

#endif