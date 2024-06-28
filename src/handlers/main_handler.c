/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:15:50 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/28 20:17:33 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

t_bool	main_handler(int c, char **v, t_cube *cube)
{
	memset(cube, 0, sizeof(t_cube));
	if (!validate_args(c, v))
		return (FALSE);
	if (!(handle_file(v[1])
			|| handle_map(v[1], cube)))
		return (FALSE);
	return (TRUE);
}
