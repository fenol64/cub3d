/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:15:26 by fnascime          #+#    #+#             */
/*   Updated: 2024/07/03 19:17:02 by aldantas         ###   ########.fr       */
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
	char		dir;
}				t_pos;

typedef struct s_ray_data
{
	double		cam_x;
	double		r_dirx;
	double		r_diry;
	int			mapx;
	int			mapy;
	double		side_disx;
	double		side_disy;
	double		d_dist_x;
	double		d_dist_y;
	double		p_wall_dis;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			draw_init;
	int			draw_end;
	int			color;
}	t_ray_data;

typedef struct s_ray
{
	double		player_x;
	double		player_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_ray;

typedef struct s_cube
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;

	char		**map;
	int			**int_map;
	int			rows;

	int			map_index;
	int			longest_row;
	t_ray		r;
	t_map_args	map_args;
	t_bool		validated_args;
	t_pos		player;
}				t_cube;

#endif
