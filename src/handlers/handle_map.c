/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:49:21 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/08 14:05:26 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

t_bool	handle_map(char *path, t_cube *cube)
{
	int	map_line;

	map_line = validate_file_args(path, cube);
	(void) map_line;
	if (!validate_map(path))
		return (FALSE);
	return (FALSE);
}
