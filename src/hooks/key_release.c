/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:30:00 by fenol             #+#    #+#             */
/*   Updated: 2024/06/16 18:13:47 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	key_release_hook(int keycode, t_cube *cube)
{
	(void)cube;
	if (keycode == KEY_ESC)
	{
		ft_printf("ESC released\n");
		exit(0);
	}
	return (0);
}
