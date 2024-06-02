/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:11:33 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/04 20:02:49 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(little) || big == little)
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			while (big[i + j]
				&& (little[j] == big[i + j])
				&& (i + j < len))
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
			j = 0;
		}
		i++;
	}
	return (0);
}
