/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:49:00 by aldantas          #+#    #+#             */
/*   Updated: 2024/07/10 02:35:22 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

void	set_wall_color(t_cube *cube, t_ray_data *ray_data)
{
	double wall_x;

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
	cube->tex_pos = (ray_data->draw_init - SCREEN_HEIGHT / 2 + ray_data->line_h / 2) * cube->tex_step;
}

t_bool open_image_texture(char *path, t_cube *cube, int i)
{
	int fd;
	int w;
	int h;
	path[ft_strlen(path) - 1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		handle_errors("Invalid file");
		return (FALSE);
	}
	if (ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4) != 0)
	{
		handle_errors("Invalid file extension");
		return (FALSE);
	}
	ft_printf("path: |%s|\n", path);
	cube->textures[i].img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr, path, &w, &h);
	if (!cube->textures[i].img_ptr)
	{
		handle_errors("Invalid file");
		return (FALSE);
	}
	cube->textures[i].img_data = (int *)mlx_get_data_addr(cube->textures[i].img_ptr, &cube->textures[i].bpp, &cube->textures[i].size_line, &cube->textures[i].endian);
	return (TRUE);
}
