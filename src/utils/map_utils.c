/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:38:58 by aldantas          #+#    #+#             */
/*   Updated: 2024/07/03 19:54:30 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int	is_player(char c)
{
	if (c == N || c == E
		|| c == S || c == W)
		return (TRUE);
	return (FALSE);
}

void	begin_map(int fd, int map_index)
{
	char	*line;

	line = get_next_line(fd);
	while (line && map_index--)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line[0] == '\0')
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

char	*ft_strdup_sw(const char *s, size_t size)
{
	char	*dup;
	size_t	len;

	dup = malloc(size + 1);
	if (dup)
	{
		len = strlen(s);
		ft_memcpy(dup, s, len);
		ft_memset(dup + len, ' ', size - len);
		dup[size] = '\0';
	}
	return (dup);
}

/*
void	print_map(char **map, int rows, int cols) // vai ser removido dps
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j++ < cols)
			printf("%c", map[i][j]);
		i++;
	}
} */

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(map[i++]);
	free(map);
}
