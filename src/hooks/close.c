/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:39:19 by fenol             #+#    #+#             */
/*   Updated: 2024/06/23 09:58:26 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

void	free_cube(t_cube *cube)
{
	(void)cube;
}

int	close_win(t_cube *cube)
{
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
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
