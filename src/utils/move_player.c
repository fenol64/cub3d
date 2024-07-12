/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:56:02 by aldantas          #+#    #+#             */
/*   Updated: 2024/07/12 19:01:30 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

static void	move_left(int keycode, t_cube *cube)
{
	double	perpendicular_x;
	double	perpendicular_y;

	if (keycode == 97 || keycode == 65)
	{
		perpendicular_x = -cube->r.dir_y;
		perpendicular_y = cube->r.dir_x;
		if (cube->int_map[(int)(cube->r.player_x + perpendicular_x
				* MOVE_SPEED)][(int)cube->r.player_y] == 0)
			cube->r.player_x += perpendicular_x * MOVE_SPEED;
		if (cube->int_map[(int)cube->r.player_x][(int)(cube->r.player_y
			+ perpendicular_y * MOVE_SPEED)] == 0)
			cube->r.player_y += perpendicular_y * MOVE_SPEED;
	}
}

static void	move_right(int keycode, t_cube *cube)
{
	double	perpendicular_x;
	double	perpendicular_y;

	if (keycode == 100 || keycode == 68)
	{
		perpendicular_x = cube->r.dir_y;
		perpendicular_y = -cube->r.dir_x;
		if (cube->int_map[(int)(cube->r.player_x + perpendicular_x
				* MOVE_SPEED)][(int)cube->r.player_y] == 0)
			cube->r.player_x += perpendicular_x * MOVE_SPEED;
		if (cube->int_map[(int)cube->r.player_x][(int)(cube->r.player_y
			+ perpendicular_y * MOVE_SPEED)] == 0)
			cube->r.player_y += perpendicular_y * MOVE_SPEED;
	}
}

static void	move_forward(int keycode, t_cube *cube)
{
	if (keycode == 119 || keycode == 87)
	{
		if (cube->int_map[(int)(cube->r.player_x + cube->r.dir_x
				* MOVE_SPEED)][(int)cube->r.player_y] == 0)
			cube->r.player_x += cube->r.dir_x * MOVE_SPEED;
		if (cube->int_map[(int)cube->r.player_x][(int)(cube->r.player_y
			+ cube->r.dir_y * MOVE_SPEED)] == 0)
			cube->r.player_y += cube->r.dir_y * MOVE_SPEED;
	}
}

static void	move_backward(int keycode, t_cube *cube)
{
	if (keycode == 115 || keycode == 83)
	{
		if (cube->int_map[(int)(cube->r.player_x - cube->r.dir_x
				* MOVE_SPEED)][(int)cube->r.player_y] == 0)
			cube->r.player_x -= cube->r.dir_x * MOVE_SPEED;
		if (cube->int_map[(int)cube->r.player_x][(int)(cube->r.player_y
			- cube->r.dir_y * MOVE_SPEED)] == 0)
			cube->r.player_y -= cube->r.dir_y * MOVE_SPEED;
	}
}

void	move_player(int keycode, t_cube *cube)
{
	move_forward(keycode, cube);
	move_backward(keycode, cube);
	move_left(keycode, cube);
	move_right(keycode, cube);
}
