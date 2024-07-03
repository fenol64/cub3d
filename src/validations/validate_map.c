/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:22:08 by aldantas          #+#    #+#             */
/*   Updated: 2024/07/03 19:56:10 by aldantas         ###   ########.fr       */
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

static int	find_player(char **map, t_pos *pos)
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
				pos->y = j;
				pos->dir = map[i][j];
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
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
	int		have_player;

	have_player = FALSE;
	get_map(path, cube);
	if (find_player(cube->map, &cube->player))
		have_player = TRUE;
	flood_fill(cube->player.x, cube->player.y, cube->map);
	if (have_player && is_valid_walls(cube->map, cube->rows))
	{
		cube->int_map = copy_char_to_int(cube->map, cube->rows,
				cube->longest_row);
		free_map(cube->map, cube->rows);
		return (TRUE);
	}
	free_map(cube->map, cube->rows);
	return (FALSE);
}
