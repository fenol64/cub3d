/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:16:27 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/06 18:46:55 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	treat_current_arg(char c, va_list argument)
{
	int	tb;

	tb = 0;
	if (c == 's')
		tb = ft_putstr(va_arg(argument, char *));
	else if (c == 'c')
		tb = ft_putchar(va_arg(argument, int));
	else if (c == '%')
		tb = ft_putchar('%');
	else if (c == 'd' || c == 'i')
		tb = ft_putnbr_base(va_arg(argument, int), 10, 0);
	else if (c == 'u')
		tb = ft_putnbr_base(va_arg(argument, unsigned int), 10, 0);
	else if (c == 'x')
		tb = ft_putnbr_base(va_arg(argument, unsigned int), 16, 0);
	else if (c == 'X')
		tb = ft_putnbr_base(va_arg(argument, unsigned int), 16, 1);
	else if (c == 'p')
		tb += ft_putptr(va_arg(argument, unsigned long int), 1);
	return (tb);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	variables;
	int		bytes_printed;

	va_start(variables, fmt);
	bytes_printed = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			bytes_printed += treat_current_arg(*(++fmt), variables);
		else
			bytes_printed += ft_putchar((char)*fmt);
		fmt++;
	}
	va_end(variables);
	return (bytes_printed);
}
