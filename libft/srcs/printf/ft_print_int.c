/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:12:15 by flren             #+#    #+#             */
/*   Updated: 2024/12/21 16:46:30 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_len(int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_print(int nb)
{
	char	d;

	if (nb >= 10)
		ft_print(nb / 10);
	d = (nb % 10) + '0';
	write(1, &d, 1);
}

int	ft_print_int(int nb)
{
	int	len;

	len = ft_len(nb);
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	ft_print(nb);
	return (len);
}
