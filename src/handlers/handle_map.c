/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:49:21 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/07 15:37:48 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

t_bool	handle_map(char *path, t_cube *cube)
{
	int	map_line;

	map_line = validate_file_args(path, cube);
	
	(void) map_line;
	//if (!validate_map(char **path)); -> validar o mapa antes do handler
	//	return (FALSE);
	return (FALSE);
}
