/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:46:10 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/02 01:51:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

static t_bool   validate_file_extension(char *path)
{
   char *extension;

    extension = ft_strrchr(path, '.');
    if (ft_strncmp(extension, ".cub", 4) == 0)
        return (TRUE);
    return (FALSE);
}

int   validate_file(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        handle_errors("Invalid file");
        return (FALSE);
    }
    if (!validate_file_extension(path))
    {
        handle_errors("Invalid file extension");
        close(fd);
        return (FALSE);
    }
    return (fd);
}





