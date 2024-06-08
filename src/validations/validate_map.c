/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:22:08 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/08 15:24:36 by aldantas         ###   ########.fr       */
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
			if (map[i][j] == 'N' || map[i][j] == 'E'
			|| map[i][j] == 'S' || map[i][j] == 'W')
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

static int	is_valid_walls(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i] != NULL)
	{
		j = 0;
		if (i == 0 || i == cube->rows)
		{
			while (cube->map[i][j] != '\0')
			{
				if (cube->map[i][j++] == 'F')
					return (FALSE);
			}
		}
		else
		{
			if ((cube->map[i][0] == 'F') ||
			(cube->map[i][ft_strlen(cube->map[i]) - 2] == 'F'))
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	validate_map(char *path, t_cube *cube)
{
	t_cube	*aux;
	t_pos	player;

	aux = cube;
	get_map(path, aux);
	find_player(aux->map, &player);
	flood_fill(player.x, player.y, aux->map);
	if (is_valid_walls(aux))
	{
		printf("O mapa é valido!");
		free_map(aux->map, aux->rows);
		return (TRUE);
	}
	else
	{
		free_map(aux->map, aux->rows);
		printf("o mapa é invalido!");
		return (FALSE);
	}
	return (FALSE);
}
