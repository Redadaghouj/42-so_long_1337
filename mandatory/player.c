/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:11:48 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/01 18:15:36 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_player *player)
{
	player->x = -1;
	player->y = 0;
}

void	check_player_position(t_player *player, int line_num, char *line)
{
	int	i;

	if (player->x != -1)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			player->x = i;
			player->y = line_num;
			break;
		}
		i++;
	}
}
