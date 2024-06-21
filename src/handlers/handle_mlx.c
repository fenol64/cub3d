/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:32:05 by fenol             #+#    #+#             */
/*   Updated: 2024/06/19 17:24:58 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

static void	register_hooks(t_cube *cube)
{
	mlx_mouse_hook(cube->win, mouse_hook, cube);
	mlx_key_hook(cube->win, key_release_hook, cube);
	mlx_hook(cube->win, 17, 0, close_hook, cube);
	mlx_hook(cube->win, 2, 1L << 0, key_press_hook, cube);
	mlx_hook(cube->win, 6, 1L << 6, mouse_move_hook, cube);
}

t_bool	handle_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			WIN_TITLE);
	if (!cube->win)
		return (0);
	register_hooks(cube);
	mlx_loop(cube->mlx);
	return (TRUE);
}
