/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:11:16 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/02 01:51:09 by codespace        ###   ########.fr       */
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