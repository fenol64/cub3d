/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:49:21 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/07 00:53:30 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

t_bool	handle_map(char *path, t_cube *cube)
{
	int	map_line;

	map_line = validate_file_args(path, cube);
	(void) map_line;
	return (FALSE);
}
