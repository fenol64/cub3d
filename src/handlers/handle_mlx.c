/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:32:05 by fenol             #+#    #+#             */
/*   Updated: 2024/06/23 10:31:43 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

static void	register_hooks(t_cube *cube)
{
	mlx_mouse_hook(cube->win_ptr, mouse_hook, cube);
	mlx_key_hook(cube->win_ptr, key_release_hook, cube);
	mlx_hook(cube->win_ptr, 17, 0, close_hook, cube);
	mlx_hook(cube->win_ptr, 2, 1L << 0, key_press_hook, cube);
	mlx_hook(cube->win_ptr, 6, 1L << 6, mouse_move_hook, cube);
}

void	render_image(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img_ptr, 0, 0);
}

static void	init_ray(t_cube *cube)
{
	cube->r.playerX = 2.0;
	cube->r.playerY = 2.0;
	cube->r.dirX = -1.0;
	cube->r.dirY = 0.0;
	cube->r.planeX = 0.0;
	cube->r.planeY = 0.66;
}

t_bool	handle_mlx(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	cube->win_ptr = mlx_new_window(cube->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			WIN_TITLE);
	if (!cube->win_ptr)
		return (0);
	cube->img_ptr = mlx_new_image(cube->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->img_data = mlx_get_data_addr(cube->img_ptr, &cube->bpp, &cube->size_line, &cube->endian);
	init_ray(cube);
	perform_raycasting(cube);
	render_image(cube);
	register_hooks(cube);
	mlx_loop(cube->mlx_ptr);
	return (TRUE);
}
