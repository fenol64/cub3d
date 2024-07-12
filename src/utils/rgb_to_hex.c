/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:46:43 by fenol             #+#    #+#             */
/*   Updated: 2024/07/11 22:54:20 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

int	rgb_to_hex(char *rgb)
{
	char	**colors;
	int		return_color;

	colors = ft_split(rgb, ',');
	return_color = ft_atoi(colors[0]) << 16 \
					| ft_atoi(colors[1]) << 8 \
					| ft_atoi(colors[2]);
	ft_free_matrix(colors);
	return (return_color);
}
