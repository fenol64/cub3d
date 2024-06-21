/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:22:49 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/19 17:41:50 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

int mouse_move_hook(int x, int y, t_cube *cube)
{
    int coord[2] = {x, y};
    int i = 0;
    mlx_clear_window(cube->mlx, cube->win);
    while (i < SCREEN_WIDTH)
    {
        mlx_pixel_put(cube->mlx, cube->win, coord[0], coord[1], 0x00FF0000);
        if (coord[0] < SCREEN_WIDTH / 2)
            coord[0]++;
        else if (coord[0] > SCREEN_WIDTH / 2)
            coord[0]--;
        
        if (coord[1] < SCREEN_HEIGHT / 2)
            coord[1]++;
        else if (coord[1] > SCREEN_HEIGHT / 2)
            coord[1]--;
        i++;
    }
    return (0);
}