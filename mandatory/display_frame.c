/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:46:50 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/04 17:45:57 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->texture->player_img->instances[0].x += 5;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->texture->player_img->instances[0].x -= 5;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->texture->player_img->instances[0].y -= 5;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->texture->player_img->instances[0].y += 5;
}

void	init_textures(t_texture *texture, mlx_t *mlx)
{
	texture->wall = mlx_load_png("mandatory/images/wall.png");
	texture->player = mlx_load_png("mandatory/images/player.png");
	texture->collectibles = mlx_load_png("mandatory/images/collect.png");
	texture->exit = mlx_load_png("mandatory/images/exit.png");
	if (!texture->wall || !texture->player
		|| !texture->collectibles || !texture->exit)
		ft_mlx_error(mlx);
}

void	init_images(t_texture *texture, mlx_t *mlx)
{
	texture->wall_img = mlx_texture_to_image(mlx, texture->wall);
	texture->player_img = mlx_texture_to_image(mlx, texture->player);
	texture->collectibles_img = mlx_texture_to_image(mlx, texture->collectibles);
	texture->exit_img = mlx_texture_to_image(mlx, texture->exit);
	if (!texture->wall_img || !texture->player_img
		|| !texture->collectibles_img || !texture->exit_img)
		ft_mlx_error(mlx);
}

int	display_images(mlx_t *mlx, t_texture *texture, t_map_info *map_info)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < map_info->lines)
	{
		j = -1;
		while (++j < map_info->rows)
		{
			if (map_info->map[i][j] == '1')
				flag = mlx_image_to_window(mlx, texture->wall_img, j * TILE, i * TILE);
			else if (map_info->map[i][j] == 'C')
				flag = mlx_image_to_window(mlx, texture->collectibles_img, j * TILE, i * TILE);
			else if (map_info->map[i][j] == 'P')
				flag = mlx_image_to_window(mlx, texture->player_img, j * TILE, i * TILE);
			else if (map_info->map[i][j] == 'E')
				flag = mlx_image_to_window(mlx, texture->exit_img, j * TILE, i * TILE);
		}
		if (flag == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	display_frame(char *map_path, t_player player, t_map_info *map_info)
{
	t_game game;

	(void)player;
	file_to_matrix(map_path, map_info);
	game.mlx = mlx_init(map_info->rows * TILE, map_info->lines * TILE, GAME_TITLE, true);
	if (!game.mlx)
		ft_mlx_error(game.mlx);
	game.texture = malloc(sizeof(t_texture));
	init_textures(game.texture , game.mlx);
	init_images(game.texture, game.mlx);
	if (display_images(game.mlx, game.texture, map_info))
	{
		mlx_close_window(game.mlx);
		ft_mlx_error(game.mlx);
	}
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
