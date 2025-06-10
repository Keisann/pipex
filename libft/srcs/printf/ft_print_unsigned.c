/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:44:05 by flren             #+#    #+#             */
/*   Updated: 2024/12/26 15:17:49 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_len(unsigned int nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len += 1;
		nb /= 10;
	}
	return (len);
}

static void	ft_print(unsigned int nb)
{
	static char	*tab;

	tab = "0123456789";
	if (nb > 9)
		ft_print(nb / 10);
	write(1, &tab[nb % 10], 1);
}

int	ft_print_unsigned(unsigned int nb)
{
	ft_print(nb);
	return (ft_len(nb));
}
