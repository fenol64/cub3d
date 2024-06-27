/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:55:56 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/27 17:02:04 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/cube.h"

void	render_image(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img_ptr, 0, 0);
}

void	draw_vertical_line(int x, int start, int end, int color, t_cube *cube) 
{
	int y;

	y = start;
	while(y <= end) 
		put_pixel(x, y++, color, cube);
}

void	put_pixel(int x, int y, int color, t_cube *cube) 
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		int pixel = (y * cube->size_line) + (x * (cube->bpp / 8));
		cube->img_data[pixel] = color & 0xFF;
		cube->img_data[pixel + 1] = (color >> 8) & 0xFF;
		cube->img_data[pixel + 2] = (color >> 16) & 0xFF;
	}
}

void draw_wall(t_cube *cube, t_ray_data *ray_data, int x)
{
	draw_vertical_line(x, ray_data->draw_init, ray_data->draw_end, ray_data->color, cube);
}

void update_image(t_cube *cube) 
{
	cube->img_ptr = mlx_new_image(cube->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->img_data = mlx_get_data_addr(cube->img_ptr, &cube->bpp, &cube->size_line, &cube->endian);
	perform_raycasting(cube);
	render_image(cube);
}