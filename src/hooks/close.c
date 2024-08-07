/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:39:19 by fenol             #+#    #+#             */
/*   Updated: 2024/08/07 01:58:50 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

void	free_cube(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < cube->rows)
	{
		free(cube->int_map[i]);
		i++;
	}
	free(cube->int_map);
	ft_free_matrix(cube->map);
	free(cube->map_args.no);
	free(cube->map_args.so);
	free(cube->map_args.we);
	free(cube->map_args.ea);
	free(cube->map_args.c);
	free(cube->map_args.f);
}

void	free_cube_no_mlx(t_cube *cube)
{
	ft_free_matrix(cube->map);
	free(cube->map_args.no);
	free(cube->map_args.so);
	free(cube->map_args.we);
	free(cube->map_args.ea);
	free(cube->map_args.c);
	free(cube->map_args.f);
}

void	free_images(t_cube *cube)
{
	int	i;

	mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(cube->mlx_ptr, cube->textures[i].img_ptr);
}

int	close_win(t_cube *cube)
{
	free_images(cube);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	mlx_destroy_display(cube->mlx_ptr);
	free(cube->mlx_ptr);
	free_cube(cube);
	ft_printf("Closing window\n");
	return (0);
}

int	close_hook(t_cube *cube)
{
	close_win(cube);
	exit(0);
	return (0);
}
