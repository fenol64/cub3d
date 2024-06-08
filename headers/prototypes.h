/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:16:39 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/08 15:13:39 by aldantas         ###   ########.fr       */
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

// validations
int		validate_map(char *path, t_cube *cube);
t_bool	validate_args(int c, char **v);
int		validate_file(char *path);
int		validate_file_args(char *file_path, t_cube *cube);
t_bool	validate_textures(char *line, t_map_args *map_args);
t_bool	validate_color(char *line);
t_bool	validate_colors(char *line, t_map_args *map_args);

// utils
void	begin_map(int fd, int map_index);
void	free_map(char **map, int rows);
void	print_map(char **map, int rows, int cols);
void	get_map(char *path, t_cube *cube);
int		get_file(char *path);
void	finish_file(int fd);

#endif
