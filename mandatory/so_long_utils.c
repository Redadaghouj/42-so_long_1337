/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:51:24 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/01 21:05:23 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_buffer(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	return (NULL);
}

void	init_map_info(t_map_info *map_info)
{
	map_info->map = NULL;
	map_info->collectibles = 0;
	map_info->exit = 0;
	map_info->path_checker = 0;
	map_info->player = 0;
	map_info->lines = 0;
	map_info->rows = 0;
}

void	init_player(t_player *player)
{
	player->x = -1;
	player->y = 0;
}
