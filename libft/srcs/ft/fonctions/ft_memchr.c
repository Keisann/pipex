/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:04:47 by flren             #+#    #+#             */
/*   Updated: 2024/12/05 18:19:55 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*s;
	char		v;
	size_t		i;

	s = (const char *) str;
	v = (char) c;
	i = 0;
	while (i < n)
	{
		if (s[i] == (char) c)
			return ((void *) &s[i]);
		i++;
	}
	return (NULL);
}
/*int main()
{
	const void *t = "Hello Flouu";
	int c = '\0';
	size_t n = 13;
	
	char *r = ft_memchr(t, c, n);
	if (r != NULL)
		printf("%s", "Trouver");
	else
		printf("%s", "Pas Trouver");
	return (0);
}*/
