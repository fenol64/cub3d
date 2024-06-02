/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:26:04 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/04 20:02:49 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	number;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	number = '0';
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	number = n % 10 + '0';
	ft_putchar_fd(number, fd);
	count++;
	return (count);
}
