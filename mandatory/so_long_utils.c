/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:51:24 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/26 20:51:48 by mdaghouj         ###   ########.fr       */
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
	map_info->collectible_count = 0;
	map_info->exit_count = 0;
	map_info->is_closed = 0;
	map_info->is_path_valid = 0;
	map_info->line_count = 0;
	map_info->player_count = 0;
}