/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:11:40 by flren             #+#    #+#             */
/*   Updated: 2024/12/26 18:19:58 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int	ft_putchar_int(char c);
int	ft_printf(const char *format, ...);
int	ft_putstr_int(const char *str);
int	ft_print_ptr(void *adr);
int	ft_print_int(int nb);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_min(unsigned int nb);
int	ft_print_max(unsigned int nb);

#endif
