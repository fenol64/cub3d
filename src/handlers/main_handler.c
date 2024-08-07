/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:15:50 by fnascime          #+#    #+#             */
/*   Updated: 2024/08/07 17:07:21 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

t_bool	main_handler(int c, char **v, t_cube *cube)
{
	ft_memset(cube, 0, sizeof(t_cube));
	if (!validate_args(c, v))
		return (FALSE);
	if (!handle_file(v[1]))
		return (FALSE);
	if (!handle_map(v[1], cube))
		return (FALSE);
	return (TRUE);
}
