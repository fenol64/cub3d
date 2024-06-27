/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:49:00 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/27 17:52:01 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

void	set_wall_color(t_cube *cube, t_ray_data *ray_data)
{
	int	map_value;

	map_value = cube->int_map[ray_data->mapx][ray_data->mapy];
	if (map_value == 1)
		ray_data->color = 0xFF0000;
	else if (map_value == 2)
		ray_data->color = 0x00FF00;
	else if (map_value == 3)
		ray_data->color = 0x0000FF;
	else if (map_value == 4)
		ray_data->color = 0xFFFFFF;
	else
		ray_data->color = 0xFFFF00;
	if (ray_data->side == 1)
		ray_data->color = ray_data->color / 2;
}
