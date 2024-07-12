/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:55:56 by aldantas          #+#    #+#             */
/*   Updated: 2024/07/11 22:47:11 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

void	render_image(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img_ptr, 0, 0);
}

void	put_pixel(int x, int y, int color, t_cube *cube)
{
	int	pixel;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		pixel = (y * cube->size_line) + (x * (cube->bpp / 8));
		cube->img_data[pixel] = color & 0xFF;
		cube->img_data[pixel + 1] = (color >> 8) & 0xFF;
		cube->img_data[pixel + 2] = (color >> 16) & 0xFF;
	}
}

void	update_image(t_cube *cube)
{
	cube->img_ptr = mlx_new_image(cube->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->img_data = mlx_get_data_addr(cube->img_ptr, &cube->bpp,
			&cube->size_line, &cube->endian);
	perform_raycasting(cube);
	render_image(cube);
}
