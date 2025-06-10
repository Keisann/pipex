/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:40:58 by flren             #+#    #+#             */
/*   Updated: 2025/01/12 17:44:59 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*d;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	d = malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	d = malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (NULL);
	while (s1[i++])
		d[i - 1] = s1[i - 1];
	while (s2[j++])
		d[i + j - 2] = s2[j - 1];
	d[i + j - 2] = '\0';
	return (d);
}
