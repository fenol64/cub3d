/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:45:59 by fenol             #+#    #+#             */
/*   Updated: 2024/07/11 22:46:03 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

void	draw_background(t_cube *cube)
{
	int	x;
	int	y;
	int	color_ceiling;
	int	color_floor;

	color_ceiling = rgb_to_hex(cube->map_args.c);
	color_floor = rgb_to_hex(cube->map_args.f);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		if (y < SCREEN_HEIGHT / 2)
			while (x < SCREEN_WIDTH)
				put_pixel(x++, y, color_ceiling, cube);
		else
			while (x < SCREEN_WIDTH)
				put_pixel(x++, y, color_floor, cube);
		y++;
	}
}
