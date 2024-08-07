/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:08:56 by fnascime          #+#    #+#             */
/*   Updated: 2024/08/07 04:00:01 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	get_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

void	finish_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	free_map_args(t_map_args *map_args)
{
	if (map_args->no)
		free(map_args->no);
	if (map_args->so)
		free(map_args->so);
	if (map_args->we)
		free(map_args->we);
	if (map_args->ea)
		free(map_args->ea);
}
