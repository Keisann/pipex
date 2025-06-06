/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:45:55 by flren             #+#    #+#             */
/*   Updated: 2025/06/06 18:11:16 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdlib.h"
# include "limits.h"
# include "fcntl.h"
# include "errno.h"
# include "wait.h"
# include "stdio.h"
# include "libft.h"

# define SUCCESS 0
# define FAIL 1

# define ERROR_AC 1
# define ERROR_PIPE 1
# define ERROR_FORK 1
# define ERROR_OPEN 1

# define ERROR_AC_MSG "Error !\n4 arguments are required !\n"
# define PIPE_MSG "Error Pipe : "
# define FORK_MSG "Error Fork : "
# define OPEN_MSG "Error Fd : "

void	ft_error(char *err_msg, char *error, int err_nb);
void	ft_free_str(char **str);
void	child1_process(char **av, int *p_fd, char **envp);
void	child2_process(char **av, int *p_fd, char **envp);
void	ft_execute_cmd(char **cmd_valid, char **envp);
char	*get_execute_path(char **envp, char **cmd_valid);
char	**get_env_path(char **envp);

#endif
