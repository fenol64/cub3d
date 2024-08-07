/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:32:37 by fnascime          #+#    #+#             */
/*   Updated: 2024/08/07 00:43:37 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

static int	have_player(char **map, t_pos *pos)
{
	int	i;
	int	j;
	int	player_idx;

	i = 0;
	player_idx = 0;
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
				player_idx++;
			}
			j++;
		}
		i++;
	}
	if (player_idx == 1)
		return (TRUE);
	return (FALSE);
}

static int	is_valid_walls(char **map, int rows)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = 0;
		if (i == 0 || i == rows - 1)
		{
			while (map[i][j] != '\0')
			{
				if (ft_strchr(WALL_INVALID, map[i][j]) != NULL)
					return (FALSE);
				j++;
			}
		}
		else
		{
			if (ft_strchr(WALL_INVALID, map[i][0]) != NULL)
				return (FALSE);
			if ((ft_strchr(WALL_INVALID, map[i][ft_strlen(map[i])
						- 2]) != NULL))
				return (FALSE);
		}
	}
	return (TRUE);
}

static int	is_valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr(MAP_CHARSET, map[i][j]) == NULL)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	validate_map(char *path, t_cube *cube)
{
	int	valid_map;

	valid_map = FALSE;
	get_map(path, cube);
	if (is_valid_map(cube->map) && have_player(cube->map, &cube->player))
		valid_map = TRUE;
	flood_fill(cube->player.x, cube->player.y, cube->map);
	if (valid_map && is_valid_walls(cube->map, cube->rows))
	{
		ft_printf("Map is valid %d \n", is_valid_map(cube->map));
		ft_printf("Map has player %d \n", have_player(cube->map,
				&cube->player));
		ft_printf("Map is valid walls %d \n", is_valid_walls(cube->map,
				cube->rows));
		cube->int_map = copy_char_to_int(cube->map, cube->rows,
				cube->longest_row);
		return (TRUE);
	}
	return (handle_errors("Map Error"), FALSE);
}
