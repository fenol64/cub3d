/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:16:39 by fnascime          #+#    #+#             */
/*   Updated: 2024/05/31 20:23:28 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H


// handlers
void    handle_errors(char *message);
t_bool    handle_map(char *path, t_cube *cube);
t_bool    handle_file(char *path);
t_bool    main_handler(int c, char **v, t_cube *cube);


// validations
t_bool    validate_args(int c, char **v);
int   validate_file(char *path);


#endif