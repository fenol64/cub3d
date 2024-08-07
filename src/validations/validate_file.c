/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:46:10 by fnascime          #+#    #+#             */
/*   Updated: 2024/08/07 04:00:05 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

static t_bool	validate_file_extension(char *path)
{
	char	*extension;

	extension = ft_strrchr(path, '.');
	if (ft_strncmp(extension, ".cub", 4) == 0)
		return (TRUE);
	return (FALSE);
}

int	validate_file(char *path)
{
	int	fd;

	fd = get_file(path);
	if (fd < 0)
	{
		handle_errors("Invalid file");
		return (FALSE);
	}
	if (!validate_file_extension(path))
	{
		handle_errors("Invalid file extension");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	validate_textures(char *line, t_map_args *map_args)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		map_args->no = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO", 2) == 0)
		map_args->so = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE", 2) == 0)
		map_args->we = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA", 2) == 0)
		map_args->ea = ft_strdup(line + 3);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	validate_colors(char *line, t_map_args *map_args)
{
	if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
	{
		if (!validate_color(line + 2))
		{
			handle_errors("Invalid floor color");
			return (FALSE);
		}
		if (!ft_strncmp(line, "F", 1))
			map_args->f = ft_strdup(line + 2);
		else
			map_args->c = ft_strdup(line + 2);
		return (TRUE);
	}
	return (FALSE);
}
