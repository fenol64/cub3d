/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:13:36 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/08 15:23:52 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

static char	*count_rows(int fd, int *rows)
{
	*rows = *rows + 1;
	return (get_next_line(fd));
}

static int	get_rows(char *path, t_cube *cube)
{
	int		fd;
	int		rows;
	char	*tmp;
	char	*line;

	fd = open(path, O_RDONLY);
	begin_map(fd, cube->map_index);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	rows = 1;
	while (line)
	{
		tmp = line;
		line = count_rows(fd, &rows);
		free(tmp);
	}
	free(line);
	close(fd);
	cube->rows = rows--;
	return (0);
}

static void	malloc_map(t_cube *cube)
{
	cube->map = malloc(sizeof(char *) * (cube->rows + 1));
	if (!cube->map)
		return ;
}

void	get_map(char *path, t_cube *cube)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	get_rows(path, cube);
	malloc_map(cube);
	fd = open(path, O_RDONLY);
	begin_map(fd, cube->map_index);
	line = (get_next_line(fd));
	while (line && i < cube->rows)
	{
		tmp = line;
		cube->map[i++] = ft_strdup(tmp);
		line = get_next_line(fd);
		free(tmp);
	}
	cube->map[i] = NULL;
	free(line);
	close(fd);
}
