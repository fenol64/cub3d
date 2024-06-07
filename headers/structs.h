/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:15:26 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/06 21:52:41 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map_args
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *C;
    char    *F;
}   t_map_args;


typedef struct s_cube
{
    char    **map;
    t_map_args  map_args;
    t_bool  validated_args;
}           t_cube;

#endif