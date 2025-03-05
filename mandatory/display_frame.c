/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:46:50 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/05 02:37:48 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hit_wall(int p_x, int p_y, mlx_instance_t *wall)
{
	int	i;

	i = 0;
	while (i < 64)
	{
		if (p_x < wall[i].x + TILE - 2 && p_x + TILE - 2 > wall[i].x &&
			p_y < wall[i].y + TILE - 2 && p_y + TILE - 2 > wall[i].y)
			return (0);
		i++;
	}
	return (1);
}

void	ft_hook(void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	new_x = game->texture->player_img->instances[0].x;
	new_y = game->texture->player_img->instances[0].y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		new_x += 5;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		new_x -= 5;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		new_y -= 5;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		new_y += 5;
	printf("%d,%d|%d,%d\n", game->texture->player_img->instances[0].x, game->texture->player_img->instances[0].y, game->texture->wall_img->instances[29].x, game->texture->wall_img->instances[29].y);
	if (hit_wall(new_x, new_y, game->texture->wall_img->instances))
	{
		game->texture->player_img->instances[0].x = new_x;
		game->texture->player_img->instances[0].y = new_y;
	}
}


void	init_textures(t_texture *texture, mlx_t *mlx)
{
	// texture->background = mlx_load_png("mandatory/images/bg.png");
	texture->wall = mlx_load_png("mandatory/images/wall.png");
	texture->player = mlx_load_png("mandatory/images/player.png");
	texture->coin = mlx_load_png("mandatory/images/collect.png");
	texture->exit = mlx_load_png("mandatory/images/exit.png");
	if (!texture->wall || !texture->player
		|| !texture->coin || !texture->exit)
		ft_mlx_error(mlx);
}

void	init_images(t_texture *texture, mlx_t *mlx)
{
	// texture->background_img = mlx_texture_to_image(mlx, texture->background);
	texture->wall_img = mlx_texture_to_image(mlx, texture->wall);
	texture->player_img = mlx_texture_to_image(mlx, texture->player);
	texture->coin_img = mlx_texture_to_image(mlx, texture->coin);
	texture->exit_img = mlx_texture_to_image(mlx, texture->exit);
	if (!texture->wall_img || !texture->player_img
		|| !texture->coin_img || !texture->exit_img)
		ft_mlx_error(mlx);
}

int	display_images(mlx_t *mlx, t_texture *texture, t_map_info *map_info)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	// flag = mlx_image_to_window(mlx, texture->background_img, 64, 64);
	while (++i < map_info->lines)
	{
		j = -1;
		while (++j < map_info->rows)
		{
			if (map_info->map[i][j] == '1')
				flag = mlx_image_to_window(mlx, texture->wall_img, j * TILE, i * TILE);
			else if (map_info->map[i][j] == 'C')
				flag = mlx_image_to_window(mlx, texture->coin_img, j * TILE, i * TILE);
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
