/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:48:19 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/27 17:03:49 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

static void	initialize_ray_data(t_cube *cube, t_ray_data *ray_data, int x)
{
	ray_data->cam_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray_data->r_dirx = cube->r.dirX + cube->r.planeX * ray_data->cam_x;
	ray_data->r_diry = cube->r.dirY + cube->r.planeY * ray_data->cam_x;
	ray_data->mapx = (int)cube->r.playerX;
	ray_data->mapy = (int)cube->r.playerY;
	ray_data->side_disx = 0;
	ray_data->side_disy = 0;
	ray_data->d_dist_x = fabs(1 / ray_data->r_dirx);
	ray_data->d_dist_y = fabs(1 / ray_data->r_diry);
	ray_data->p_wall_dis = 0;
	ray_data->step_x = 0;
	ray_data->step_y = 0;
	ray_data->hit = 0;
	ray_data->side = 0;
}

static void	calculate_side_distance(t_cube *cube, t_ray_data *ray_data)
{
	if (ray_data->r_dirx < 0)
	{
		ray_data->step_x = -1;
		ray_data->side_disx = (cube->r.playerX - ray_data->mapx) * ray_data->d_dist_x;
	}
	else
	{
		ray_data->step_x = 1;
		ray_data->side_disx = (ray_data->mapx + 1.0 - cube->r.playerX) * ray_data->d_dist_x;
	}
	if (ray_data->r_diry < 0)
	{
		ray_data->step_y = -1;
		ray_data->side_disy = (cube->r.playerY - ray_data->mapy) * ray_data->d_dist_y;
	}
	else
	{
		ray_data->step_y = 1;
		ray_data->side_disy = (ray_data->mapy + 1.0 - cube->r.playerY) * ray_data->d_dist_y;
	}
}

static void	find_hit(t_cube *cube, t_ray_data *ray_data)
{
	while (ray_data->hit == 0)
	{
		if (ray_data->side_disx < ray_data->side_disy)
		{
			ray_data->side_disx += ray_data->d_dist_x;
			ray_data->mapx += ray_data->step_x;
			ray_data->side = 0;
		}
		else
		{
			ray_data->side_disy += ray_data->d_dist_y;
			ray_data->mapy += ray_data->step_y;
			ray_data->side = 1;
		}
		if (cube->int_map[ray_data->mapx][ray_data->mapy] > 0)
			ray_data->hit = 1;
	}
}

static void	calculates(t_cube *cube, t_ray_data *ray_data)
{
	if (ray_data->side == 0)
		ray_data->p_wall_dis = (ray_data->mapx - cube->r.playerX + (1 - ray_data->step_x) / 2) / ray_data->r_dirx;
	else
		ray_data->p_wall_dis = (ray_data->mapy - cube->r.playerY + (1 - ray_data->step_y) / 2) / ray_data->r_diry;

	ray_data->line_h = (int)(SCREEN_HEIGHT / ray_data->p_wall_dis);

	ray_data->draw_init = -ray_data->line_h / 2 + SCREEN_HEIGHT / 2;
	if (ray_data->draw_init < 0)
		ray_data->draw_init = 0;
	ray_data->draw_end = ray_data->line_h / 2 + SCREEN_HEIGHT / 2;
	if (ray_data->draw_end >= SCREEN_HEIGHT)
		ray_data->draw_end = SCREEN_HEIGHT - 1;
}

void	set_wall_color(t_cube *cube, t_ray_data *ray_data)
{
	switch (cube->int_map[ray_data->mapx][ray_data->mapy])
	{
	case 1:
		ray_data->color = 0xFF0000;
		break;
	case 2:
		ray_data->color = 0x00FF00;
		break;
	case 3:
		ray_data->color = 0x0000FF;
		break;
	case 4:
		ray_data->color = 0xFFFFFF;
		break;
	default:
		ray_data->color = 0xFFFF00;
		break;
	}
	if (ray_data->side == 1)
	{
		ray_data->color = ray_data->color / 2;
	}
}

void	perform_raycasting(t_cube *cube)
{
	int x;
	t_ray_data ray_data;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		initialize_ray_data(cube, &ray_data, x);
		calculate_side_distance(cube, &ray_data);
		find_hit(cube, &ray_data);
		calculates(cube, &ray_data);
		set_wall_color(cube, &ray_data); // essa função vai ser trocada pela função que pega a cor da textura;
		draw_wall(cube, &ray_data, x);
		x++;
	}
}
