/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:16:39 by fnascime          #+#    #+#             */
/*   Updated: 2024/08/06 22:40:12 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "cube.h"

// handlers
void	handle_errors(char *message);
t_bool	handle_map(char *path, t_cube *cube);
t_bool	handle_file(char *path);
t_bool	main_handler(int c, char **v, t_cube *cube);
t_bool	handle_mlx(t_cube *cube);

// validations
int		validate_map(char *path, t_cube *cube);
t_bool	validate_all_tex_path(t_cube *cube);
t_bool	validate_args(int c, char **v);
int		validate_file(char *path);
int		validate_file_args(char *file_path, t_cube *cube);
t_bool	validate_textures(char *line, t_map_args *map_args);
t_bool	validate_color(char *line);
t_bool	validate_colors(char *line, t_map_args *map_args);

// utils
int		flood_fill(int x, int y, char **map);
char	*ft_strdup_sw(const char *s, size_t size);
char	**copy_map(char **map);
void	begin_map(int fd, int map_index);
void	free_map(char **map, int rows);
void	print_map(char **map, int rows, int cols);
void	get_map(char *path, t_cube *cube);
int		is_player(char c);
int		get_file(char *path);
void	finish_file(int fd);
int		rgb_to_hex(char *rgb);

// hooks
void	free_cube(t_cube *cube);
int		close_hook(t_cube *cube);
int		key_press_hook(int keycode, t_cube *cube);
int		key_release_hook(int keycode, t_cube *cube);
int		mouse_hook(int button, int x, int y, t_cube *cube);
int		mouse_move_hook(int x, int y, t_cube *cube);
void	move_player(int keycode, t_cube *cube);

// rays
int		**copy_char_to_int(char **char_matrix, int rows, int cols);
void	draw_wall(t_cube *cube, t_ray_data *ray_data, int x);
void	draw_vertical_line(int x, t_ray_data *ray_data, t_cube *cube);
void	render_image(t_cube *cube);
void	draw_wall(t_cube *cube, t_ray_data *ray_data, int x);
void	put_pixel(int x, int y, int color, t_cube *cube);
void	update_image(t_cube *cube);
void	perform_raycasting(t_cube *cube);
void	set_wall_color(t_cube *cube, t_ray_data *ray_data);
void	draw_background(t_cube *cube);
t_bool	open_image_texture(char *path, t_cube *cube, int i);
void	draw_minimap(t_cube *cube);

#endif
