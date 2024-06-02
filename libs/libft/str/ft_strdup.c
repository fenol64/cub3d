/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:04:02 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/04 20:02:49 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret_str;
	size_t	i;

	ret_str = malloc(ft_strlen(s) + 1);
	i = 0;
	if (!ret_str)
		return (NULL);
	while (s[i])
	{
		ret_str[i] = s[i];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
