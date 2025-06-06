/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:50:51 by flren             #+#    #+#             */
/*   Updated: 2025/06/06 18:23:26 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(char **av, int *p_fd, char **envp)
{
	int	fd;
	char **cmd_valid;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		ft_error(OPEN_MSG, strerror(errno), ERROR_OPEN);
	}
	close(p_fd[0]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	cmd_valid = ft_split(av[2], ' ');
	ft_execute_cmd(cmd_valid, envp);
}

void	child2_process(char **av, int *p_fd, char **envp)
{
	int	fd;
	char **cmd_valid;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		ft_error(OPEN_MSG, strerror(errno), ERROR_OPEN);
	}
	close(p_fd[1]);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	cmd_valid = ft_split(av[3], ' ');
	ft_execute_cmd(cmd_valid, envp);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	status;
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		ft_error(ERROR_AC_MSG, NULL, ERROR_AC);
	if (pipe(fd) == -1)
		ft_error(PIPE_MSG, strerror(errno), ERROR_PIPE);
	pid1 = fork();
	if (pid1 == -1)
		ft_error(FORK_MSG, strerror(errno), ERROR_FORK);
	if (pid1 == 0)
		child1_process(av, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_error(FORK_MSG, strerror(errno), ERROR_FORK);
	if (pid2 == 0)
		child2_process(av, fd, envp);
	close(fd[0]);
	close(fd[1]);
	status = 0;
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}
