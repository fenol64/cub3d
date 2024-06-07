/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:11:16 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/06 23:54:07 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

int    validate_args(int c, char **v)
{
    if (c != 2)
    {
        handle_errors("Invalid number of arguments");
        return (TRUE);
    }
    if (ft_strncmp(v[1] + ft_strlen(v[1]) - 4, ".cub", 4) != 0)
    {
        handle_errors("Invalid file extension");
        return (TRUE);
    }
    return (FALSE);
}

t_bool validate_color(char *line)
{
    char **color;
    int i;
    int j;

    i = 0;
    j = 0;
    color = ft_split(line, ',');
    while (color[i])
    {
        j = 0;
        while (color[i][j])
        {
            if (!ft_isdigit(color[i][j]))
                break;
            j++;
        }
        i++;
    }
    ft_free_matrix(color);
    if (i != 3)
        return (FALSE);
    return (TRUE);
}

int validate_arg(char *line, t_map_args *map_args)
{
    if (ft_strncmp(line, "F", 1) == 0)
    {
        if (!validate_color(line + 2))
        {
            handle_errors("Invalid floor color");
            return (FALSE);
        }
        map_args->F = ft_strdup(line + 2);
    }
    else if (ft_strncmp(line, "C", 1) == 0)
    {
        if (!validate_color(line + 2))
        {
            handle_errors("Invalid ceiling color");
            return (FALSE);
        }
        map_args->C = ft_strdup(line + 2);
    }
    else if (ft_strncmp(line, "NO", 2) == 0)
        map_args->NO = ft_strdup(line + 3);
    else if (ft_strncmp(line, "SO", 2) == 0)
        map_args->SO = ft_strdup(line + 3);
    else if (ft_strncmp(line, "WE", 2) == 0)
        map_args->WE = ft_strdup(line + 3);
    else if (ft_strncmp(line, "EA", 2) == 0)
        map_args->EA = ft_strdup(line + 3);
    else
    {
        printf("line: %s\n", line);
        handle_errors("Invalid argument");
        return (FALSE);
    }
    return (TRUE);
}

t_bool validated_all_args(t_map_args map_args)
{
    if (map_args.F && map_args.C && map_args.NO && map_args.SO && map_args.WE && map_args.EA)
        return (TRUE);
    return (FALSE);
}

int validate_file_args(char *file_path, t_cube *cube)
{
    char *line;
    int map_index;
    int fd;
    
    fd = get_file(file_path);   
    map_index = 0;
    line = get_next_line(fd);
    while (!cube->validated_args && line)
    {
        if (validated_all_args(cube->map_args))
        {
            cube->validated_args = TRUE;
            break;
        }
        if (*line != '\n')
        {     
            if (!validate_arg(line, &cube->map_args))
                break;
            free(line);
            line = get_next_line(fd);
            map_index++;
        }
        else 
        {
            free(line);
            line = get_next_line(fd);
        }
    }
    finish_file(fd);
    if (cube->validated_args)
        return map_index;
    handle_errors("Invalid arguments");
    return (FALSE);
}