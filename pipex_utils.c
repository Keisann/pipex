/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:10:00 by flren             #+#    #+#             */
/*   Updated: 2025/06/04 18:40:58 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *err_msg, int err_nb)
{
	perror(err_msg);
	exit(err_nb);
}

void	ft_error(char *err_msg, int err_nb)
{
	ft_putstr_fd(err_msg, STDERR_FILENO);
	exit(err_nb);
}
