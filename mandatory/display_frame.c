/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:46:50 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/03 17:35:34 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *) param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	// else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	// 	texture.player_img->instances[0].x += 5;
	// else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	// 	texture.player_img->instances[0].x -= 5;
	// else if (mlx_is_key_down(mlx, MLX_KEY_UP))
	// 	texture.player_img->instances[0].y -= 5;
	// else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	// 	texture.player_img->instances[0].y += 5;
}

void	inti_textures(t_texture *texture, mlx_t *mlx)
{
	texture->wall = mlx_load_png("mandatory/images/wall.png");
	texture->player = mlx_load_png("mandatory/images/player.png");
	texture->collectibles = mlx_load_png("mandatory/images/collect.png");
	texture->exit = mlx_load_png("mandatory/images/exit.png");
	if (!texture->wall || !texture->player
		|| !texture->collectibles || !texture->exit)
		ft_mlx_error(mlx);
}

void	inti_images(t_texture *texture, mlx_t *mlx)
{
	texture->wall_img = mlx_texture_to_image(mlx, texture->wall);
	texture->player_img = mlx_texture_to_image(mlx, texture->player);
	texture->collectibles_img = mlx_texture_to_image(mlx, texture->collectibles);
	texture->exit_img = mlx_texture_to_image(mlx, texture->exit);
	if (!texture->wall_img || !texture->player_img
		|| !texture->collectibles_img || !texture->exit_img)
		ft_mlx_error(mlx);
}

int	display_images(mlx_t *mlx, t_texture texture)
{
	if (mlx_image_to_window(mlx, texture.player_img, 0, 0) == -1)
		return (-1);
	else if (mlx_image_to_window(mlx, texture.collectibles_img, 100, 100) == -1)
		return (-1);
	else if (mlx_image_to_window(mlx, texture.wall_img, 200, 200) == -1)
		return (-1);
	return (EXIT_SUCCESS);
}

void	display_frame(char *map_path, t_player player, t_map_info *map_info)
{
	mlx_t			*mlx;
	t_texture	texture;

	(void)player;
	file_to_matrix(map_path, map_info);
	mlx = mlx_init(WIDTH, HEIGHT, GAME_TITLE, true);
	if (!mlx)
		ft_mlx_error(mlx);
	inti_textures(&texture , mlx);
	inti_images(&texture, mlx);
	if (display_images(mlx, texture) == -1)
	{
		mlx_close_window(mlx);
		ft_mlx_error(mlx);
	}
	// if (mlx_image_to_window(mlx, texture.background_img, 0, 0) == -1)
	// {
	// 	mlx_close_window(mlx);
	// 	ft_mlx_error(mlx);
	// }
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, texture.background_img);
	mlx_terminate(mlx);
}
