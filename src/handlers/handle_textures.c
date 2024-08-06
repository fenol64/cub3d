/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:49:00 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/02 16:53:54 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

void	draw_wall(t_cube *cube, t_ray_data *ray_data, int x)
{
	draw_vertical_line(x, ray_data, cube);
}

void	draw_vertical_line(int x, t_ray_data *ray_data, t_cube *cube)
{
	int	index;
	int	tex_y;

	index = ray_data->draw_init;
	while (index < ray_data->draw_end)
	{
		tex_y = (int)cube->tex_pos & (IMAGE_HEIGHT - 1);
		cube->tex_pos += cube->tex_step;
		if (ray_data->side == 1 && ray_data->r_diry < 0)
			put_pixel(x, index, cube->textures[0].img_data[
				(int)(IMAGE_WIDTH * tex_y + cube->tex_x)], cube);
		else if (ray_data->side == 1 && ray_data->r_diry > 0)
			put_pixel(x, index, cube->textures[1].img_data[
				(int)(IMAGE_WIDTH * tex_y + cube->tex_x)], cube);
		else if (ray_data->side == 0 && ray_data->r_dirx < 0)
			put_pixel(x, index, cube->textures[2].img_data[
				(int)(IMAGE_WIDTH * tex_y + cube->tex_x)], cube);
		else if (ray_data->side == 0 && ray_data->r_dirx > 0)
			put_pixel(x, index, cube->textures[3].img_data[
				(int)(IMAGE_WIDTH * tex_y + cube->tex_x)], cube);
		index++;
	}
}

void	set_wall_color(t_cube *cube, t_ray_data *ray_data)
{
	double	wall_x;

	if (ray_data->side == 0)
		wall_x = cube->r.player_y + ray_data->p_wall_dis * ray_data->r_diry;
	else
		wall_x = cube->r.player_x + ray_data->p_wall_dis * ray_data->r_dirx;
	wall_x -= floor(wall_x);
	cube->tex_x = (int)(wall_x * (double)IMAGE_WIDTH);
	if (ray_data->side == 0 && ray_data->r_dirx > 0)
		cube->tex_x = IMAGE_WIDTH - cube->tex_x - 1;
	if (ray_data->side == 1 && ray_data->r_diry < 0)
		cube->tex_x = IMAGE_WIDTH - cube->tex_x - 1;
	cube->tex_step = 1.0 * IMAGE_HEIGHT / ray_data->line_h;
	cube->tex_pos = (ray_data->draw_init - SCREEN_HEIGHT
			/ 2 + ray_data->line_h / 2) * cube->tex_step;
}

t_bool	open_image_texture(char *path, t_cube *cube, int i)
{
	int	w;
	int	h;

	cube->textures[i].img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
			path, &w, &h);
	if (!cube->textures[i].img_ptr)
		return (handle_errors("Invalid file"), FALSE);
	cube->textures[i].img_data = (int *)mlx_get_data_addr(cube->textures[i]
			.img_ptr, &cube->textures[i].bpp, &cube->textures[i].size_line,
			&cube->textures[i].endian);
	return (TRUE);
}
