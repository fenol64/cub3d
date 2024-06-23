/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:41:31 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/23 04:59:04 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int **copy_char_to_int(char **char_matrix, int rows, int cols) 
{
	int **int_matrix;
	int i = 0, j;

	// Aloca memória para as linhas da matriz de inteiros
	int_matrix = (int **)malloc(rows * sizeof(int *));
	if (!int_matrix)
		return NULL;

	while (i < rows) {
		// Aloca memória para cada coluna da linha atual
		int_matrix[i] = (int *)malloc(cols * sizeof(int));
		if (!int_matrix[i]) 
		{
			// Se falhar, libera toda a memória previamente alocada
			while (i > 0) 
				free(int_matrix[--i]);
			free(int_matrix);
			return (NULL);
		}

		j = 0;
		while (j < cols) 
		{
			// Converte cada char para int e copia para a matriz de inteiros
			if (ft_isdigit(char_matrix[i][j]))
				int_matrix[i][j] = char_matrix[i][j] - '0';
			else
				int_matrix[i][j] = char_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (int_matrix);
}