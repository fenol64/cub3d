/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:38:58 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/07 18:54:26 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

void	print_map(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j++ < cols)
			printf("%c", map[i][j]);
		i++;
	}
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(map[i++]);
	free(map);
}
