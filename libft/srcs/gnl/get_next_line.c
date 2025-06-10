/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:07:14 by flren             #+#    #+#             */
/*   Updated: 2025/02/07 13:09:29 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*new_line(char *line)
{
	char	*new_line;
	char	*reste;

	new_line = ft_strchr(line, '\n');
	if (!new_line)
		return (NULL);
	reste = ft_strdup(new_line + 1);
	new_line++;
	if (!reste)
		return (NULL);
	*new_line = '\0';
	return (reste);
}

static char	*read_line(char *line, int fd, char *buffer)
{
	char	*temp;
	int		bytes;

	if (!line)
		line = ft_strdup("");
	while (!ft_strchr(line, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 1)
			break ;
		buffer[bytes] = '\0';
		temp = ft_strjoin(line, buffer);
		if (!temp)
			return (NULL);
		free (line);
		line = temp;
	}
	if (*line == '\0')
	{
		free (line);
		line = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*dest;
	char		*line;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free (dest);
		free (buffer);
		dest = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_line(dest, fd, buffer);
	free (buffer);
	if (!line || *line == '\0')
	{
		free(line);
		dest = NULL;
		return (NULL);
	}
	dest = new_line(line);
	return (line);
}
