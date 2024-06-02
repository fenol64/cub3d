/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:43:58 by fnascime          #+#    #+#             */
/*   Updated: 2024/03/12 20:55:56 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	find_current_line(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*return_current_line(char *res)
{
	int		i;
	int		check;
	int		size;
	char	*line;

	size = 0;
	check = 0;
	while (res[size] && res[size] != '\n')
		size++;
	if (res[size] == '\n')
		check++;
	line = malloc((size + check + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*return_after_sep(char *res)
{
	char	*new_res;
	int		i;
	int		size;

	size = 0;
	while (res[size] && res[size] != '\n')
		size++;
	if (!res[size])
	{
		free(res);
		return (NULL);
	}
	size++;
	new_res = malloc((ft_strlen(res) - size + 1) * sizeof(char));
	if (!new_res)
		return (NULL);
	i = 0;
	while (res[size + i])
	{
		new_res[i] = res[size + i];
		i++;
	}
	new_res[i] = '\0';
	free(res);
	return (new_res);
}

static char	*read_file(int fd)
{
	int			read_return;
	char		*line;
	static char	*res[MAX_FD] = {NULL};

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	read_return = 1;
	while (read_return > 0 && !find_current_line(res[fd]))
	{
		read_return = read(fd, line, BUFFER_SIZE);
		if (read_return < 0)
		{
			free(line);
			return (NULL);
		}
		line[read_return] = '\0';
		res[fd] = ft_strjoin_gnl(res[fd], line);
	}
	free(line);
	if (!res[fd])
		return (NULL);
	line = return_current_line(res[fd]);
	res[fd] = return_after_sep(res[fd]);
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_file(fd));
}

/*#include <fcntl.h>
#include <stdio.h>
int     main(int c, char **v)
{
        int             fd;
        char  *line;
        (void) c;

        fd = open(v[1], O_RDONLY);
        //printf("%s", get_next_line(fd));
        while ((line = get_next_line(fd)))
        {
                printf("%s", line);
                free(line);
        }
        return (0);
}*/
