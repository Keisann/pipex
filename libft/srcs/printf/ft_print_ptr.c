/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:25:28 by flren             #+#    #+#             */
/*   Updated: 2024/12/21 17:00:43 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_len(unsigned long adr)
{
	size_t	len;

	len = 0;
	if (adr == 0)
		return (1);
	while (adr > 0)
	{
		len++;
		adr /= 16;
	}
	return (len);
}

static void	ft_print(unsigned long adr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (adr >= 16)
		ft_print(adr / 16);
	write(1, &hex[adr % 16], 1);
}

int	ft_print_ptr(void *adr)
{
	size_t	len;

	if (adr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = ft_len((unsigned long)adr);
	write(1, "0x", 2);
	ft_print((unsigned long) adr);
	return (len + 2);
}
