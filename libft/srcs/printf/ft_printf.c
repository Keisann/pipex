/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:28:48 by flren             #+#    #+#             */
/*   Updated: 2025/02/11 18:03:50 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_checker(char lettre, va_list args)
{
	if (lettre == '%')
		return (write(1, "%", 1));
	if (lettre == 'c')
		return (ft_putchar_int((char)va_arg(args, int)));
	if (lettre == 's')
		return (ft_putstr_int((char *)va_arg(args, long)));
	if (lettre == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (lettre == 'd' || lettre == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (lettre == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (lettre == 'x')
		return (ft_print_min(va_arg(args, unsigned int)));
	if (lettre == 'X')
		return (ft_print_max(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_checker(format[i], args);
		}
		else
		{
			len += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
