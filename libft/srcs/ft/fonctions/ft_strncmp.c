/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:52:36 by flren             #+#    #+#             */
/*   Updated: 2024/12/03 14:09:56 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (s1[i] == '\0' || s2[i] == '\0' )
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	const char *s1 = "Hhhhhhallo";
	const char *s2 = "Hhhhhhzllo";
	size_t n = 10;

	printf("%d", ft_strncmp(s1, s2, n));
}*/
