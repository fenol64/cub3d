/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:38:37 by fenol             #+#    #+#             */
/*   Updated: 2024/07/11 22:44:30 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

void	draw_minimap_square(t_cube *cube, int i, int j, int color)
{
	int	x;
	int	y;

	x = i * 10;
	while (x < (i + 1) * 10)
	{
		y = j * 10;
		while (y < (j + 1) * 10)
		{
			put_pixel(x, y, color, cube);
			y++;
		}
		x++;
	}
}

void	draw_minimap(t_cube *cube)
{
	int	i;
	int	j;
	int	margin;

	margin = 1;
	i = 0;
	while (i < cube->rows)
	{
		j = 0;
		while (cube->map[i][j] != '\0')
		{
			if (cube->int_map[i][j] == 1)
				draw_minimap_square(cube, i + margin, j + margin, 0x000000);
			else if (cube->int_map[i][j] == 0)
				draw_minimap_square(cube, i + margin, j + margin, 0xFFFFFF);
			j++;
		}
		i++;
	}
	draw_minimap_square(cube, (int)(cube->r.player_x) + margin,
		(int)(cube->r.player_y) + margin, 0xFF0000);
}
