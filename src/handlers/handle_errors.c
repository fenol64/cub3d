/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:50:52 by fnascime          #+#    #+#             */
/*   Updated: 2024/06/02 01:51:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube.h"

void   handle_errors(char *error)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(error, 2);
    ft_putstr_fd("\n", 2);
}