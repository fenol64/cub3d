/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:42:11 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/04 20:02:49 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ret;
	const char	*origin;

	ret = dest;
	origin = src;
	if (!dest && !src)
		return (0);
	if (dest < src)
		ft_memcpy(ret, src, n);
	else
	{
		while (n--)
		{
			ret[n] = origin[n];
		}
	}
	return (ret);
}
