/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:18:46 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/26 22:11:35 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_msg(char *msg)
{
	write(STD_ERROR, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	free_map_and_exit(char **map, char *msg)
{
	free_buffer(map);
	exit_msg(msg);
}
