/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:32:05 by fenol             #+#    #+#             */
/*   Updated: 2024/07/10 15:52:17 by aldantas         ###   ########.fr       */
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

static void	set_dir_player(t_cube *cube)
{
	if (cube->player.dir == 'N')
	{
		cube->r.dir_x = -1;
		cube->r.dir_y = 0;
		cube->r.plane_x = 0;
		cube->r.plane_y = 0.66;
	}
	if (cube->player.dir == 'S')
	{
		cube->r.dir_x = 1;
		cube->r.dir_y = 0;
		cube->r.plane_x = 0;
		cube->r.plane_y = -0.66;
	}
}

static void	set_dir_player2(t_cube *cube)
{
	if (cube->player.dir == 'W')
	{
		cube->r.dir_x = 0;
		cube->r.dir_y = -1;
		cube->r.plane_x = -0.66;
		cube->r.plane_y = 0;
	}
	if (cube->player.dir == 'E')
	{
		cube->r.dir_x = 0;
		cube->r.dir_y = 1;
		cube->r.plane_x = 0.66;
		cube->r.plane_y = 0;
	}
}

static void	init_ray(t_cube *cube)
{
	cube->r.player_x = cube->player.x + 0.5;
	cube->r.player_y = cube->player.y + 0.5;
	set_dir_player(cube);
	set_dir_player2(cube);
}

t_bool	handle_mlx(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	cube->win_ptr = mlx_new_window(cube->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			WIN_TITLE);
	if (!cube->win_ptr)
		return (0);
	cube->img_ptr = mlx_new_image(cube->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->img_data = mlx_get_data_addr(cube->img_ptr, &cube->bpp,
			&cube->size_line, &cube->endian);
	if (!open_image_texture(cube->map_args.no, cube, 0)
		|| !open_image_texture(cube->map_args.so, cube, 1)
		|| !open_image_texture(cube->map_args.we, cube, 2)
		|| !open_image_texture(cube->map_args.ea, cube, 3))
		return (FALSE);
	init_ray(cube);
	draw_background(cube);
	perform_raycasting(cube);
	render_image(cube);
	register_hooks(cube);
	mlx_loop(cube->mlx_ptr);
	return (TRUE);
}
