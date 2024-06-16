/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:25:11 by fenol             #+#    #+#             */
/*   Updated: 2024/06/16 18:11:29 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	key_press_hook(int keycode, t_cube *cube)
{
	(void)cube;
	ft_printf("im pressing a key %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
