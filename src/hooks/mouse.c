/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:32:58 by fenol             #+#    #+#             */
/*   Updated: 2024/08/07 04:00:43 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	mouse_hook(int button, int x, int y, t_cube *cube)
{
	(void)cube;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}
