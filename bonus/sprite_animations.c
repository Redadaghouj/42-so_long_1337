/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:07:20 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/10 23:32:58 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sprite_animation_door(t_game game)
{
	mlx_texture_t	*copy_texture;

	copy_texture = mlx_load_png("bonus/textures/exit_open_bonus.png");
	if (!copy_texture)
	{
		mlx_delete_texture(copy_texture);
		mlx_close_window(game.mlx);
	}
	ft_memcpy(game.texture->exit_img->pixels, copy_texture->pixels, T * T * 4);
	mlx_delete_texture(copy_texture);
}

void	sprite_animation(t_game game, char *img_path)
{
	mlx_texture_t	*copy_texture;

	copy_texture = mlx_load_png(img_path);
	if (!copy_texture)
	{
		mlx_delete_texture(copy_texture);
		mlx_close_window(game.mlx);
	}
	ft_memcpy(game.texture->player_img->pixels,
		copy_texture->pixels, T * T * 4);
	mlx_delete_texture(copy_texture);
}

void	sprite_animation_enemy(t_game game)
{
	mlx_texture_t	*copy_texture;

	copy_texture = mlx_load_png(game.enemy_imgs[!game.enemy_state]);
	if (!copy_texture)
	{
		mlx_delete_texture(copy_texture);
		mlx_close_window(game.mlx);
	}
	ft_memcpy(game.texture->enemy_img->pixels, copy_texture->pixels, T * T * 4);
	mlx_delete_texture(copy_texture);
}
