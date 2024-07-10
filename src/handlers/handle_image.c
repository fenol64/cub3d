/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:55:56 by aldantas          #+#    #+#             */
/*   Updated: 2024/07/10 07:03:36 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

void	render_image(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img_ptr, 0, 0);
}

void	draw_vertical_line(int x, t_ray_data *ray_data, t_cube *cube)
{
	int index;
	index = ray_data->draw_init;
	while (index < ray_data->draw_end)
	{
		int tex_y = (int)cube->tex_pos & (IMAGE_HEIGHT - 1);
		cube->tex_pos += cube->tex_step;
		if (ray_data->side == 1 && ray_data->r_diry < 0)
			put_pixel(x, index, cube->textures[0].img_data[
				(int)(IMAGE_WIDTH * tex_y + cube->tex_x)
			], cube);
		else if (ray_data->side == 1 && ray_data->r_diry > 0)
			put_pixel(x, index, cube->textures[1].img_data[
				(int)(IMAGE_WIDTH * tex_y + cube->tex_x)
			], cube);
		else if (ray_data->side == 0 && ray_data->r_dirx < 0)
			put_pixel(x, index, cube->textures[2].img_data[
				(int)(IMAGE_WIDTH * tex_y + cube->tex_x)
			], cube);
		else if (ray_data->side == 0 && ray_data->r_dirx > 0)
			put_pixel(x, index, cube->textures[3].img_data[
				(int)(IMAGE_WIDTH * tex_y + cube->tex_x)
			], cube);
		index++;
	}
	
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

void	draw_wall(t_cube *cube, t_ray_data *ray_data, int x)
{
	draw_vertical_line(x, ray_data, cube);
}

void	update_image(t_cube *cube)
{
	cube->img_ptr = mlx_new_image(cube->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->img_data = mlx_get_data_addr(cube->img_ptr, &cube->bpp,
			&cube->size_line, &cube->endian);
	perform_raycasting(cube);
	render_image(cube);
}

int rgb_to_hex(char *rgb)
{
	char **colors;
	int return_color;

	colors = ft_split(rgb, ',');
	return_color = ft_atoi(colors[0]) << 16 | ft_atoi(colors[1]) << 8 | ft_atoi(colors[2]);
	ft_free_matrix(colors);
	return return_color;
}
void draw_background(t_cube *cube)
{
	int x;
	int y;
	int color_ceiling;
	int color_floor;

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
