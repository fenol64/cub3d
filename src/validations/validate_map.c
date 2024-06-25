/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:22:08 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/25 19:19:31 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

static int	is_valid(int x, int y, char **map)
{
	if (x >= 0 && map[x] && y >= 0 && map[x][y] && (map[x][y] == '0'
		|| map[x][y] == ' '))
		return (1);
	return (0);
}

static int	flood_fill(int x, int y, char **map)
{
	if (!is_valid(x, y, map) || map[x][y] == 'F')
		return (0);
	map[x][y] = 'F';
	if (flood_fill(x + 1, y, map))
		return (1);
	if (flood_fill(x - 1, y, map))
		return (1);
	if (flood_fill(x, y + 1, map))
		return (1);
	if (flood_fill(x, y - 1, map))
		return (1);
	return (0);
}

static void	find_player(char **map, t_pos *pos)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (is_player(map[i][j]))
			{
				pos->x = i;
				pos->y = j - 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

static int	is_valid_walls(char **map, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		if (i == 0 || i == rows)
		{
			while (map[i][j] != '\0')
			{
				if (map[i][j++] == 'F')
					return (FALSE);
			}
		}
		else
		{
			if ((map[i][0] == 'F') ||
			(map[i][ft_strlen(map[i]) - 2] == 'F'))
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	validate_map(char *path, t_cube *cube)
{
	char	**aux_map;

	get_map(path, cube);
	aux_map = copy_map(cube->map);
	find_player(aux_map, &cube->player);
	flood_fill(cube->player.x, cube->player.y, aux_map);
	if (is_valid_walls(aux_map, cube->rows))
	{
		cube->int_map = copy_char_to_int(cube->map, cube->rows, cube->longest_row);
		free_map(aux_map, cube->rows);
		printf("cube->rows: %d\n", cube->rows); // -> o numero de rows está maior doq realmente é, causando segfault. solução: adaptar a função get_rows
		printf("Mapa de inteiro\n");			// para contar apenas as linhas com algum conteudo
		if (cube->int_map)
		{
		for (int i = 0; i < cube->rows; i++) {
        	for (int j = 0; j < cube->longest_row; j++) {
                printf("%d ", cube->int_map[i][j]);
            }
            printf("\n");
        }
		}
		return (TRUE);
	}
	else
	{
		free_map(aux_map, cube->rows);
		free_map(cube->map, cube->rows);
		return (FALSE);
	}
	return (FALSE);
}
