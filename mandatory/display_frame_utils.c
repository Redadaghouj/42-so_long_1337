/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:46:50 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/06 01:19:48 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_texture *texture, mlx_t *mlx)
{
	texture->wall = mlx_load_png("mandatory/images/wall.png");
	texture->player = mlx_load_png("mandatory/images/player.png");
	texture->collect = mlx_load_png("mandatory/images/collect.png");
	texture->exit = mlx_load_png("mandatory/images/exit.png");
	if (!texture->wall || !texture->player
		|| !texture->collect || !texture->exit)
		ft_mlx_error(mlx);
}

void	init_images(t_texture *texture, mlx_t *mlx)
{
	texture->wall_img = mlx_texture_to_image(mlx, texture->wall);
	texture->player_img = mlx_texture_to_image(mlx, texture->player);
	texture->collect_img = mlx_texture_to_image(mlx, texture->collect);
	texture->exit_img = mlx_texture_to_image(mlx, texture->exit);
	if (!texture->wall_img || !texture->player_img
		|| !texture->collect_img || !texture->exit_img)
		ft_mlx_error(mlx);
}

int	collision_check(int p_x, int p_y, mlx_instance_t *wall, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (p_x < wall[i].x + T - 4 && p_x + T - 4 > wall[i].x
			&& p_y < wall[i].y + T - 2 && p_y + T - 2 > wall[i].y)
			return (0);
		i++;
	}
	return (1);
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
