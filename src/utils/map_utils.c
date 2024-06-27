/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:38:58 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/27 17:12:13 by aldantas         ###   ########.fr       */
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

char	**copy_map(char **map)
{
	char	**copy_map;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy_map = malloc(sizeof(char *) * (i + 1));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy_map[i] = ft_strdup(map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
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
