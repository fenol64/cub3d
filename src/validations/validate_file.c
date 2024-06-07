/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:46:10 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/06 23:29:11 by fnascime         ###   ########.fr       */
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

    if (!validate_file_extension(path))
    {
        handle_errors("Invalid file extension");
        return (FALSE);
    }
    fd = get_file(path);
    if (fd == -1)
    {
        handle_errors("Invalid file");
        return (FALSE);
    }
    return (TRUE);
}





