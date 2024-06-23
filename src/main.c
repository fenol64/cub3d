/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:24:04 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/23 08:37:04 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

int	main(int c, char **v)
{
	t_cube	cube;

	if (!main_handler(c, v, &cube))
		return (1);
	handle_mlx(&cube);
	return (0);
}

// # define MAP_WIDTH 24
// # define MAP_HEIGHT 24
// # define MOVE_SPEED 0.4
// # define ROTATE_SPEED 0.2
// # define screenWidth 1920
// # define screenHeight 1200

// typedef struct
// {
// 	double playerX;
// 	double playerY;
// 	double dirX;
// 	double dirY;
// 	double planeX;
// 	double planeY;
// }	t_ray;

// typedef struct {
// 	int		map[MAP_WIDTH][MAP_HEIGHT];
// 	void	*mlx_ptr; 
// 	void	*win_ptr; 
// 	void	*img_ptr; 
// 	char	*img_data;
// 	int		bpp;
// 	int		size_line;
// 	int		endian;

// 	t_ray	r;
// }	z_cube;

// static void	init_ray(z_cube *cube)
// {
// 	cube->r.playerX = 22.0;
// 	cube->r.playerY = 12.0;
// 	cube->r.dirX = -1.0;
// 	cube->r.dirY = 0.0;
// 	cube->r.planeX = 0.0;
// 	cube->r.planeY = 0.66;
// }

// void	put_pixel(int x, int y, int color, z_cube *cube) 
// {
// 	if (x >= 0 && x < screenWidth && y >= 0 && y < screenHeight) {
// 		int pixel = (y * cube->size_line) + (x * (cube->bpp / 8));
// 		cube->img_data[pixel] = color & 0xFF;
// 		cube->img_data[pixel + 1] = (color >> 8) & 0xFF;
// 		cube->img_data[pixel + 2] = (color >> 16) & 0xFF;
// 	}
// }

// void	initialize_mlx(z_cube *cube) 
// {
// 	cube->mlx_ptr = mlx_init();
// 	cube->win_ptr = mlx_new_window(cube->mlx_ptr, screenWidth, screenHeight, "Cub3D");
// 	cube->img_ptr = mlx_new_image(cube->mlx_ptr, screenWidth, screenHeight);
// 	cube->img_data = mlx_get_data_addr(cube->img_ptr, &cube->bpp, &cube->size_line, &cube->endian);
// }

// void	render_image(z_cube *cube)
// {
// 	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img_ptr, 0, 0);
// }

// void	draw_vertical_line(int x, int start, int end, int color, z_cube *cube) 
// {
// 	int y;

// 	y = start;
// 	while(y <= end) 
// 		put_pixel(x, y++, color, cube);
// }

// void	perform_raycasting(z_cube *cube) 
// {
// 	for (int x = 0; x < screenWidth; x++) {
// 		double cameraX = 2 * x / (double)screenWidth - 1;
// 		double rayDirX = cube->r.dirX + cube->r.planeX * cameraX;
// 		double rayDirY = cube->r.dirY + cube->r.planeY * cameraX;

// 		int mapX = (int)cube->r.playerX;
// 		int mapY = (int)cube->r.playerY;

// 		double sideDistX;
// 		double sideDistY;

// 		double deltaDistX = fabs(1 / rayDirX);
// 		double deltaDistY = fabs(1 / rayDirY);
// 		double perpWallDist;

// 		int stepX;
// 		int stepY;
// 		int hit = 0;
// 		int side;

// 		if (rayDirX < 0) {
// 			stepX = -1;
// 			sideDistX = (cube->r.playerX - mapX) * deltaDistX;
// 		} else {
// 			stepX = 1;
// 			sideDistX = (mapX + 1.0 - cube->r.playerX) * deltaDistX;
// 		}
// 		if (rayDirY < 0) {
// 			stepY = -1;
// 			sideDistY = (cube->r.playerY - mapY) * deltaDistY;
// 		} else {
// 			stepY = 1;
// 			sideDistY = (mapY + 1.0 - cube->r.playerY) * deltaDistY;
// 		}

// 		while (hit == 0) {
// 			if (sideDistX < sideDistY) {
// 				sideDistX += deltaDistX;
// 				mapX += stepX;
// 				side = 0;
// 			} else {
// 				sideDistY += deltaDistY;
// 				mapY += stepY;
// 				side = 1;
// 			}
// 			if (cube->map[mapX][mapY] > 0) hit = 1;
// 		}

// 		if (side == 0) perpWallDist = (mapX - cube->r.playerX + (1 - stepX) / 2) / rayDirX;
// 		else perpWallDist = (mapY - cube->r.playerY + (1 - stepY) / 2) / rayDirY;

// 		int lineHeight = (int)(screenHeight / perpWallDist);

// 		int drawStart = -lineHeight / 2 + screenHeight / 2;
// 		if (drawStart < 0) drawStart = 0;
// 		int drawEnd = lineHeight / 2 + screenHeight / 2;
// 		if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

// 		int color;
// 		switch(cube->map[mapX][mapY]) {
// 			case 1:  color = 0xFF0000;  break;
// 			case 2:  color = 0x00FF00;  break;
// 			case 3:  color = 0x0000FF;  break;
// 			case 4:  color = 0xFFFFFF;  break;
// 			default: color = 0xFFFF00;  break;
// 		}

// 		if (side == 1) { color = color / 2; }

// 		draw_vertical_line(x, drawStart, drawEnd, color, cube);
// 	}
// }

// void update_image(z_cube *cube) {
// 	cube->img_ptr = mlx_new_image(cube->mlx_ptr, screenWidth, screenHeight);
// 	cube->img_data = mlx_get_data_addr(cube->img_ptr, &cube->bpp, &cube->size_line, &cube->endian);
// 	perform_raycasting(cube);
// 	render_image(cube);
// }

// int handle_keypress(int keycode, z_cube *cube) {
// 	if (keycode == 65307) // ESC key
// 		exit(0);
// 	if (keycode == 119) { // W key
// 		if (cube->map[(int)(cube->r.playerX + cube->r.dirX * MOVE_SPEED)][(int)cube->r.playerY] == 0) cube->r.playerX += cube->r.dirX * MOVE_SPEED;
// 		if (cube->map[(int)cube->r.playerX][(int)(cube->r.playerY + cube->r.dirY * MOVE_SPEED)] == 0) cube->r.playerY += cube->r.dirY * MOVE_SPEED;
// 	}
// 	if (keycode == 115) { // S key
// 		if (cube->map[(int)(cube->r.playerX - cube->r.dirX * MOVE_SPEED)][(int)cube->r.playerY] == 0) cube->r.playerX -= cube->r.dirX * MOVE_SPEED;
// 		if (cube->map[(int)cube->r.playerX][(int)(cube->r.playerY - cube->r.dirY * MOVE_SPEED)] == 0) cube->r.playerY -= cube->r.dirY * MOVE_SPEED;
// 	}
// 	if (keycode == 100) { // A key
// 		double oldDirX = cube->r.dirX;
// 		cube->r.dirX = cube->r.dirX * cos(-ROTATE_SPEED) - cube->r.dirY * sin(-ROTATE_SPEED);
// 		cube->r.dirY = oldDirX * sin(-ROTATE_SPEED) + cube->r.dirY * cos(-ROTATE_SPEED);
// 		double oldPlaneX = cube->r.planeX;
// 		cube->r.planeX = cube->r.planeX * cos(-ROTATE_SPEED) - cube->r.planeY * sin(-ROTATE_SPEED);
// 		cube->r.planeY = oldPlaneX * sin(-ROTATE_SPEED) + cube->r.planeY * cos(-ROTATE_SPEED);
// 	}
// 	if (keycode == 97) { // D key
// 		double oldDirX = cube->r.dirX;
// 		cube->r.dirX = cube->r.dirX * cos(ROTATE_SPEED) - cube->r.dirY * sin(ROTATE_SPEED);
// 		cube->r.dirY = oldDirX * sin(ROTATE_SPEED) + cube->r.dirY * cos(ROTATE_SPEED);
// 		double oldPlaneX = cube->r.planeX;
// 		cube->r.planeX = cube->r.planeX * cos(ROTATE_SPEED) - cube->r.planeY * sin(ROTATE_SPEED);
// 		cube->r.planeY = oldPlaneX * sin(ROTATE_SPEED) + cube->r.planeY * cos(ROTATE_SPEED);
// 	}
// 	update_image(cube);
// 	return 0;
// }

// int main() {
// 	// Inicialize a MinilibX

// 	// Inicialize o mapa
// 	z_cube cube = {
// 		.map = {
// 			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// 		}
// 	};


// 	initialize_mlx(&cube);
// 	//incializa as variaveis do ray
// 	init_ray(&cube);
	
// 	// Executa o raycasting
// 	perform_raycasting(&cube);

// 	// Renderiza a imagem na janela
// 	render_image(&cube);

// 	mlx_key_hook(cube.win_ptr, handle_keypress, &cube);

// 	// Loop da MinilibX
// 	mlx_loop(cube.mlx_ptr);
// 	return 0;
// }