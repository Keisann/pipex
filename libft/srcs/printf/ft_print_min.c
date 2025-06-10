/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:35:11 by flren             #+#    #+#             */
/*   Updated: 2024/12/26 17:52:37 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len += 1;
		nb /= 16;
	}
	return (len);
}

static void	ft_print(unsigned int nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_print(nb / 16);
	write(1, &hex[nb % 16], 1);
}

int	ft_print_min(unsigned int nb)
{
	ft_print(nb);
	return (ft_len(nb));
}
