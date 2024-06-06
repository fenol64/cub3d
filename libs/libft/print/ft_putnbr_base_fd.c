/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:41:52 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/06 18:48:34 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_base_fd(long long int nbr, int base, int is_upper, int fd)
{
	int		bytes_printed;
	char	*base_str;

	bytes_printed = 0;
	if (is_upper)
		base_str = "0123456789ABCDEF";
	else
		base_str = "0123456789abcdef";
	if (nbr < 0)
	{
		bytes_printed += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= base)
		bytes_printed += ft_putnbr_base_fd(nbr / base, base, is_upper, fd);
	bytes_printed += ft_putchar_fd(base_str[nbr % base], fd);
	return (bytes_printed);
}
