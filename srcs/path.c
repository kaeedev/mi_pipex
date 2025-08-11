/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:52:07 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 09:52:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i] + 5);
		}
		i ++;
	}
	return (NULL);
}

char	*create_path(char *dir, char *cmd)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(dir, "/");
	result = ft_strjoin(temp, cmd);
	free(temp);
	return (result);
}

char	*find_command_path(char *cmd, char **envp)
{
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));

	char	*path;
	char	*full_path;
	char	**dirs;
	int		i;

	i = 0;
	path = get_env_path(envp);
	dirs = ft_split(path, ':');
	while(dirs[i])
	{
		full_path = create_path(dirs[i], cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i ++;
	}
	return (NULL);
}
