/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:10:00 by flren             #+#    #+#             */
/*   Updated: 2025/06/06 19:11:51 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_env_path(char **envp)
{
	int	i;

	i = 0;
	while(envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*get_execute_path(char **envp, char **cmd_valid)
{
	int i;
	char *execute_path;
	char *cmd;

	i = 0;
	cmd = ft_strjoin("/", cmd_valid[0]);
	while (envp[i])
	{
		execute_path = ft_strjoin(envp[i], cmd);
		if (access(execute_path, X_OK & F_OK) == SUCCESS)
		{
			free(cmd);
			return (execute_path);
		}
		free(execute_path);
		i++;
	}
	free(cmd);
	return (NULL);
}

void	ft_execute_cmd(char **cmd_valid, char **envp)
{
	char **path_set;
	char *execute_path;

	path_set = NULL;
	if (access(cmd_valid[0], X_OK & F_OK) == SUCCESS)
		execute_path = ft_strdup(cmd_valid[0]);
	else
	{
		path_set = get_env_path(envp);
		if (path_set == NULL)
		{
			ft_free_str(cmd_valid);
			ft_error("Error Env path !\n", NULL, FAIL);
		}
		execute_path = get_execute_path(path_set, cmd_valid);
		if (!execute_path)
		{
			(ft_free_str(cmd_valid),ft_free_str(path_set));
			ft_error("Error execute_path !\n", NULL, FAIL);
		}
	}
	execve(execute_path, cmd_valid, envp);
	ft_free_str(cmd_valid);
	ft_free_str(path_set);
	ft_error("Error command not found !\n", NULL, FAIL);
}

void	ft_error(char *err_msg, char *error, int err_nb)
{
	if (error)
	{
		ft_putstr_fd(err_msg, STDERR_FILENO);
		ft_putstr_fd(error, STDERR_FILENO);
	}
	else 
		ft_putstr_fd(err_msg, STDERR_FILENO);
	exit(err_nb);
}

void	ft_free_str(char **str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
