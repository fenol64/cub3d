/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:25:11 by fenol             #+#    #+#             */
/*   Updated: 2024/07/10 09:34:13 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	key_press_hook(int keycode, t_cube *cube)
{
	(void) cube;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
