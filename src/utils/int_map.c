/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:41:31 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/07 00:38:24 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	**copy_char_to_int(char **char_matrix, int rows, int cols)
{
	int	**int_matrix;
	int	i;
	int	j;

	i = 0;
	int_matrix = (int **)malloc(rows * sizeof(int *));
	if (!int_matrix)
		return (NULL);
	while (i < rows)
	{
		int_matrix[i] = (int *)malloc(cols * sizeof(int));
		if (!int_matrix[i])
			return (NULL);
		j = 0;
		while (j < cols)
		{
			if (ft_isdigit(char_matrix[i][j]))
				int_matrix[i][j] = char_matrix[i][j] - '0';
			else
				int_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (int_matrix);
}
