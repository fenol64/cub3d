/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:50:52 by fnascime          #+#    #+#             */
/*   Updated: 2024/05/31 19:59:22 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube.h"

void   handle_errors(char *error)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(error, 2);
    ft_putstr_fd("\n", 2);
}