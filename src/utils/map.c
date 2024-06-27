/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:13:36 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/26 21:40:50 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

static void	get_longest_row(char *line, t_cube *cube)
{
	int line_len;

	line_len = ft_strlen(line);
	if (cube->longest_row != 0)
	{
		if (cube->longest_row < line_len)
			cube->longest_row = line_len;
	}
	else
		cube->longest_row = line_len;
} 

static int	get_rows(char *path, t_cube *cube)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(path, O_RDONLY);
	begin_map(fd, cube->map_index);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	rows = 0;
	while (line)
	{
		get_longest_row(line, cube);
		free(line);
		rows++;
		line = get_next_line(fd);
	}
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
	int		fd;
	int		i;

	i = 0;
	get_rows(path, cube);
	malloc_map(cube);
	fd = open(path, O_RDONLY);
	begin_map(fd, cube->map_index);
	line = get_next_line(fd);
	while (line && i < cube->rows)
	{
		cube->map[i++] = ft_strdup_sw(line, cube->longest_row);
		free(line);
		line = get_next_line(fd);
	}
	cube->map[i] = NULL;
	free(line);
	close(fd);
}
