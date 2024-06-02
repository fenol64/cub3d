/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:25:30 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/04 20:02:49 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	get_size(int n)
{
	int	number_len;

	number_len = 0;
	if (n < 0)
	{
		number_len++;
		n *= -1;
	}
	while (n > 0)
	{
		number_len++;
		n /= 10;
	}
	return (number_len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		number_len;

	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	number_len = get_size(n);
	res = (char *) malloc(sizeof(char) * number_len + 1);
	if (!res)
		return (NULL);
	res[number_len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		res[number_len - 1] = n % 10 + '0';
		n /= 10;
		number_len--;
	}
	return (res);
}
