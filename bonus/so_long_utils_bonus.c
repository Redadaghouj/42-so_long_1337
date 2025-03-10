/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:46:57 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/10 00:15:58 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_game(t_game *game, t_map_info map_info)
{
	game->collect = map_info.collectibles;
	game->map = map_info.map;
	game->steps_counter = 1;
	game->counter = 0;
	game->enemy_state = 0;
	game->enemy_imgs[0] = "bonus/image_bonus/enemy_2_bonus.png";
	game->enemy_imgs[1] = "bonus/image_bonus/enemy_bonus.png";
}

int	key_press(t_game *game, char *image_path, int x, int y)
{
	sprite_animation(*game, image_path);
	if (collision_check(x, y, game->texture->wall_img->instances, 
			game->texture->wall_img->count))
	{
		print_steps(game);
	}
	return (5);
}

void	enemy_frame_change(t_game *game)
{
	if (game->counter > SPEED_FRAME)
	{
		sprite_animation_enemy(*game);
		game->enemy_state = !game->enemy_state;
		game->counter = 0;
	}
}
