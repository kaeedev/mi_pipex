/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:43:00 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/11 18:32:38 by marvin           ###   ########.fr       */
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

# include "mi_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		**pipes;
	int		here_doc_pipe[2];
	pid_t	*pids;
	pid_t	here_doc_pid;
}	t_pipex;

// Prototipos de funciones
// parsing.c Valida argumentos y archivos
void	ft_error(int i); //Para mensajes de error y terminar el programa
//Comprueba si los argumentos son correctos y si es modo here_doc
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

//MODO HERE_DOC

// here_doc.c - Gestiona el modo here_doc
//Dirige la ejecucion en modo here_doc
void	handle_here_doc_mode(int argc, char **argv, char **envp);
//Hace fork de los procesos necesarios para la pipeline en modo here_doc
void	create_here_doc_processes(int num_cmds, t_pipex *px);
//Lee lineas del usuario hasta el limitador y las pasa por un pipe
void	handle_here_doc(char *limiter, int pipe_fd[2]);
//Configura la entrada del primer comando en modo here_doc
void	setup_here_doc_first_command(int here_doc_pipe[2], int **pipes);
//Ejecuta uno de los comandos de la pipeline en modo here_doc
void	execute_here_doc_command(int cmd_index, t_pipex *px);
//Configura la entrada/salida del ultimo comando en modo here_doc
void	setup_here_doc_last_command(char **argv, int argc, int **pipes,
			int cmd_index);

// here_doc_mode.c - Gestiona el modo here_doc
//Reserva y prepara todos los recursos necesarios para el modo here_doc
int		**setup_here_doc_resources(int argc, pid_t **pids,
			int here_doc_pipe[2]);
//Crea un proceso hijo encargado de leer la entrada del usuario 
// hasta el limitador
pid_t	create_here_doc_input_process(char *limiter, int here_doc_pipe[2]);
// Crea todos los procesos hijos para ejecutar la pipeline en modo here_doc
void	execute_here_doc_pipeline(t_pipex *px);
//Libera y cierra todos los recursos usados en modo here_doc
void	cleanup_here_doc_resources(t_pipex *px);

#endif