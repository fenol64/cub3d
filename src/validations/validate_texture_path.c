/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:56:25 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/06 22:09:44 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

static t_bool	valid_tex_path(char *path)
{
	int	fd;

	path[ft_strlen(path) - 1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (handle_errors("Invalid file"), FALSE);
	return (TRUE);
}

t_bool	validate_all_tex_path(t_cube *cube)
{
	if (!valid_tex_path(cube->map_args.no) || !valid_tex_path(cube->map_args.so)
		|| !valid_tex_path(cube->map_args.we)
		|| !valid_tex_path(cube->map_args.ea))
		return (FALSE);
	return (TRUE);
}
