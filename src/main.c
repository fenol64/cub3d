/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:24:04 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/27 18:01:31 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

int	main(int c, char **v)
{
	t_cube	cube;

	if (!main_handler(c, v, &cube))
		return (1);
	handle_mlx(&cube);
	return (0);
}
