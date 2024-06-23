/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:15:26 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/23 09:46:04 by aldantas         ###   ########.fr       */
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

typedef struct
{
	double playerX;
	double playerY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
}	t_ray;

typedef struct s_cube
{
	void	*mlx_ptr; 
	void	*win_ptr; 
	void	*img_ptr; 
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;

	char		**map;
	int			**int_map;
	int			rows;
	int			cols;
	
	int			map_index;
	t_ray	r;
	t_map_args	map_args;
	t_bool		validated_args;
	t_pos		player;
}				t_cube;

#endif
