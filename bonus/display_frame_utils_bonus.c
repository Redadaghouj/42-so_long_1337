/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:46:50 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/08 01:15:15 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_textures(t_texture *texture)
{
	texture->wall = mlx_load_png("bonus/image_bonus/wall_bonus.png");
	texture->player = mlx_load_png("bonus/image_bonus/p_right_bonus.png");
	texture->collect = mlx_load_png("bonus/image_bonus/collect_bonus.png");
	texture->exit = mlx_load_png("bonus/image_bonus/exit_bonus.png");
	texture->enemy = mlx_load_png("bonus/image_bonus/enemy_2_bonus.png");
	if (!texture->wall || !texture->player || !texture->enemy
		|| !texture->collect || !texture->exit)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_images(t_texture *texture, mlx_t *mlx)
{
	texture->wall_img = mlx_texture_to_image(mlx, texture->wall);
	texture->player_img = mlx_texture_to_image(mlx, texture->player);
	texture->collect_img = mlx_texture_to_image(mlx, texture->collect);
	texture->exit_img = mlx_texture_to_image(mlx, texture->exit);
	texture->enemy_img = mlx_texture_to_image(mlx, texture->enemy);
	if (!texture->wall_img || !texture->player_img || !texture->enemy_img
		|| !texture->collect_img || !texture->exit_img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	collision_collect(int p_x, int p_y, mlx_instance_t *coin, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (p_x < coin[i].x + T - 10 && p_x + T - 10 > coin[i].x
			&& p_y < coin[i].y + T - 10 && p_y + T - 10 > coin[i].y)
			return (i);
		i++;
	}
	return (-1);
}

void	free_textures(t_texture *texture)
{
	if (texture->wall)
		mlx_delete_texture(texture->wall);
	if (texture->player)
		mlx_delete_texture(texture->player);
	if (texture->collect)
		mlx_delete_texture(texture->collect);
	if (texture->exit)
		mlx_delete_texture(texture->exit);
	if (texture->enemy)
		mlx_delete_texture(texture->enemy);
}

void	free_images(t_texture *texture, mlx_t *mlx)
{
	if (texture->wall_img)
		mlx_delete_image(mlx, texture->wall_img);
	if (texture->player_img)
		mlx_delete_image(mlx, texture->player_img);
	if (texture->collect_img)
		mlx_delete_image(mlx, texture->collect_img);
	if (texture->exit_img)
		mlx_delete_image(mlx, texture->exit_img);
	if (texture->enemy_img)
		mlx_delete_image(mlx, texture->enemy_img);
}
