/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:50:51 by flren             #+#    #+#             */
/*   Updated: 2025/06/04 19:13:31 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	pid_t	pid1;
	pid_t	pid2;
	
	if (ac != 5)
		ft_error(ERROR_AC_MSG, ERROR_AC);
	if (pipe(fd) == -1)
		ft_perror("Error Pipe ", ERROR_PIPE);
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("Error Fork ", ERROR_FORK);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("Error Fork ", ERROR_FORK);
}
