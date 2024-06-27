/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:48:19 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/26 21:51:54 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

void	draw_vertical_line(int x, int start, int end, int color, t_cube *cube) 
{
	int y;

	y = start;
	while(y <= end) 
		put_pixel(x, y++, color, cube);
}

void	put_pixel(int x, int y, int color, t_cube *cube) 
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
		int pixel = (y * cube->size_line) + (x * (cube->bpp / 8));
		cube->img_data[pixel] = color & 0xFF;
		cube->img_data[pixel + 1] = (color >> 8) & 0xFF;
		cube->img_data[pixel + 2] = (color >> 16) & 0xFF;
	}
}

void update_image(t_cube *cube) 
{
	cube->img_ptr = mlx_new_image(cube->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->img_data = mlx_get_data_addr(cube->img_ptr, &cube->bpp, &cube->size_line, &cube->endian);
	perform_raycasting(cube);
	render_image(cube);
}

void perform_raycasting(t_cube *cube)
{
	int x;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int color;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
		rayDirX = cube->r.dirX + cube->r.planeX * cameraX;
		rayDirY = cube->r.dirY + cube->r.planeY * cameraX;
		mapX = (int)cube->r.playerX;
		mapY = (int)cube->r.playerY;
		sideDistX = 0;
		sideDistY = 0;
		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		perpWallDist = 0;
		stepX = 0;
		stepY = 0;
		hit = 0;
		side = 0;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cube->r.playerX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cube->r.playerX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cube->r.playerY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cube->r.playerY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (cube->int_map[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - cube->r.playerX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - cube->r.playerY + (1 - stepY) / 2) / rayDirY;
		lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
		drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		switch (cube->int_map[mapX][mapY])
		{
		case 1:
			color = 0xFF0000;
			break;
		case 2:
			color = 0x00FF00;
			break;
		case 3:
			color = 0x0000FF;
			break;
		case 4:
			color = 0xFFFFFF;
			break;
		default:
			color = 0xFFFF00;
			break;
		}
		if (side == 1)
		{
			color = color / 2;
		}
		draw_vertical_line(x, drawStart, drawEnd, color, cube);
		x++;
	}
}