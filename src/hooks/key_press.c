/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:25:11 by fenol             #+#    #+#             */
/*   Updated: 2024/08/06 22:20:26 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	key_press_hook(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC)
		close_hook(cube);
	return (0);
}
