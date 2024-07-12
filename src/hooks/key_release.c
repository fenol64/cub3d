/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:30:00 by fenol             #+#    #+#             */
/*   Updated: 2024/07/12 18:56:31 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

static void	look(t_cube *cube, double angle)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = cube->r.dir_x;
	oldplane_x = cube->r.plane_x;
	cube->r.dir_x = cube->r.dir_x * cos(angle) - cube->r.dir_y * sin(angle);
	cube->r.dir_y = olddir_x * sin(angle) + cube->r.dir_y * cos(angle);
	cube->r.plane_x = cube->r.plane_x * cos(angle)
		- cube->r.plane_y * sin(angle);
	cube->r.plane_y = oldplane_x * sin(angle) + cube->r.plane_y * cos(angle);
}

int	key_release_hook(int keycode, t_cube *cube)
{
	(void)cube;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	if (keycode == 65307)
		exit(0);
	move_player(keycode, cube);
	if (keycode == 65363)
		look(cube, -ROTATE_SPEED);
	if (keycode == 65361)
		look(cube, ROTATE_SPEED);
	update_image(cube);
	return (0);
}
