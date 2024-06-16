/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:39:19 by fenol             #+#    #+#             */
/*   Updated: 2024/06/16 18:11:08 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

void	free_cube(t_cube *cube)
{
	(void)cube;
}

int	close_win(t_cube *cube)
{
	mlx_destroy_window(cube->mlx, cube->win);
	ft_printf("Window closed\n");
	free_cube(cube);
	return (0);
}

int	close_hook(t_cube *cube)
{
	close_win(cube);
	exit(0);
	return (0);
}
