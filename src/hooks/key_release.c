/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:30:00 by fenol             #+#    #+#             */
/*   Updated: 2024/06/23 10:42:18 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	key_release_hook(int keycode, t_cube *cube)
{
	(void)cube;
	if (keycode == KEY_ESC)
	{
		ft_printf("ESC released\n");
		exit(0);
	}
	if (keycode == 65307) // ESC key
		exit(0);
	if (keycode == 119) { // W key
		if (cube->int_map[(int)(cube->r.playerX + cube->r.dirX * MOVE_SPEED)][(int)cube->r.playerY] == 0) cube->r.playerX += cube->r.dirX * MOVE_SPEED;
		if (cube->int_map[(int)cube->r.playerX][(int)(cube->r.playerY + cube->r.dirY * MOVE_SPEED)] == 0) cube->r.playerY += cube->r.dirY * MOVE_SPEED;
	}
	if (keycode == 115) { // S key
		if (cube->int_map[(int)(cube->r.playerX - cube->r.dirX * MOVE_SPEED)][(int)cube->r.playerY] == 0) cube->r.playerX -= cube->r.dirX * MOVE_SPEED;
		if (cube->int_map[(int)cube->r.playerX][(int)(cube->r.playerY - cube->r.dirY * MOVE_SPEED)] == 0) cube->r.playerY -= cube->r.dirY * MOVE_SPEED;
	}
	if (keycode == 100) { // A -> olhar para a esquerda
		double oldDirX = cube->r.dirX;
		cube->r.dirX = cube->r.dirX * cos(-ROTATE_SPEED) - cube->r.dirY * sin(-ROTATE_SPEED);
		cube->r.dirY = oldDirX * sin(-ROTATE_SPEED) + cube->r.dirY * cos(-ROTATE_SPEED);
		double oldPlaneX = cube->r.planeX;
		cube->r.planeX = cube->r.planeX * cos(-ROTATE_SPEED) - cube->r.planeY * sin(-ROTATE_SPEED);
		cube->r.planeY = oldPlaneX * sin(-ROTATE_SPEED) + cube->r.planeY * cos(-ROTATE_SPEED);
	}
	if (keycode == 97) { // D -> olhar para a direita
		double oldDirX = cube->r.dirX;
		cube->r.dirX = cube->r.dirX * cos(ROTATE_SPEED) - cube->r.dirY * sin(ROTATE_SPEED);
		cube->r.dirY = oldDirX * sin(ROTATE_SPEED) + cube->r.dirY * cos(ROTATE_SPEED);
		double oldPlaneX = cube->r.planeX;
		cube->r.planeX = cube->r.planeX * cos(ROTATE_SPEED) - cube->r.planeY * sin(ROTATE_SPEED);
		cube->r.planeY = oldPlaneX * sin(ROTATE_SPEED) + cube->r.planeY * cos(ROTATE_SPEED);
	}
	update_image(cube);
	return (0);
}
