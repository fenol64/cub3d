/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:15:26 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/16 18:17:51 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map_args
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*c;
	char		*f;
}				t_map_args;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_cube
{
	void		*mlx;
	void		*win;
	char		**map;
	t_map_args	map_args;
	int			rows;
	int			map_index;
	t_bool		validated_args;
	t_pos		player;
}				t_cube;

#endif
