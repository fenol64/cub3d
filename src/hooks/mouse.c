/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:32:58 by fenol             #+#    #+#             */
/*   Updated: 2024/06/16 18:17:02 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	mouse_hook(int button, int x, int y, t_cube *cube)
{
	(void)cube;
	printf("Mouse button %d pressed at %d %d\n", button, x, y);
	return (0);
}
