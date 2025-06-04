/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:45:55 by flren             #+#    #+#             */
/*   Updated: 2025/06/04 18:46:28 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdlib.h"
# include "limits.h"
# include "fcntl.h"
# include "stdio.h"
# include "libft.h"

# define SUCCESS 0
# define FAIL 1

# define ERROR_AC 1
# define ERROR_PIPE 1
# define ERROR_FORK 1

# define ERROR_AC_MSG "Error !\n4 arguments are required !\n"
# define ERROR_PIPE_MSG "Error Pipe !\n"
# define ERROR_FORK_MSG "Error Fork !\n"

void	ft_error(char *err_msg, int err_nb);
void	ft_perror(char *err_msg, int err_nb);

#endif
