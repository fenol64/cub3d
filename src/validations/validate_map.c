/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:22:08 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/07 17:44:30 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/cube.h"

static int	is_valid(int x, int y, char **map)
{
	if (x >= 0 && map[x] && y >= 0 && map[x][y] && (map[x][y] == '0'))
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

static void find_player(char **map, t_pos *pos)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' || map[i][j] == 'W')
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

int	valid_map(char	*path)
{
	t_cube	aux;
	t_pos	player;

	player.x = 0;
	player.y = 0;
	get_map(path, &aux);
	print_map(aux.map, 15, 33);
	find_player(aux.map, &player);
	flood_fill(player.x, player.y, aux.map);
	printf("\n x: %d, y: %d\n", player.x, player.y);
	printf("\ndepois do fill\n");
	print_map(aux.map, 15, 33);
	free_map(aux.map, 15);
	return (FALSE);
}
