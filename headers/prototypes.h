/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:16:39 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/07 01:12:02 by fnascime         ###   ########.fr       */
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
t_bool	validate_args(int c, char **v);
int		validate_file(char *path);
int		validate_file_args(char *file_path, t_cube *cube);
t_bool	validate_textures(char *line, t_map_args *map_args);
t_bool	validate_color(char *line);
t_bool	validate_colors(char *line, t_map_args *map_args);

// utils
int		get_file(char *path);
void	finish_file(int fd);

#endif