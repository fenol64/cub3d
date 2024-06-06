/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:43:48 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/06 18:43:06 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_number(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	else if (ft_islower(c))
		return (c - 'a' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	final_number;
	int	signal;

	i = 0;
	final_number = 0;
	signal = 1;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (ft_isalnum(str[i]))
	{
		final_number = final_number * str_base + get_number(str[i]);
		i++;
	}
	return (final_number * signal);
}
