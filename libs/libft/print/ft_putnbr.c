/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:26:04 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/06 18:50:03 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr(int n)
{
	char	number;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	number = '0';
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	number = n % 10 + '0';
	ft_putchar(number);
	count++;
	return (count);
}
