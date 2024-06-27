/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:49:21 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/26 21:43:19 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

t_bool	handle_map(char *path, t_cube *cube)
{
	if (!validate_file_args(path, cube))
		return (FALSE);
	if (!validate_map(path, cube))
		return (FALSE);
	return (TRUE);
}
