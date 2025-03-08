/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:46:50 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/08 01:10:34 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_hook(void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	new_x = game->texture->player_img->instances[0].x;
	new_y = game->texture->player_img->instances[0].y;
	game->counter++;
	enemy_frame_change(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		new_x += handle_key_press(*game, "bonus/image_bonus/p_right_bonus.png");
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		new_x -= handle_key_press(*game, "bonus/image_bonus/p_left_bonus.png");
	else if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		new_y -= handle_key_press(*game, "bonus/image_bonus/p_up_bonus.png");
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		new_y += handle_key_press(*game, "bonus/image_bonus/p_down_bonus.png");
	collision(game, new_x, new_y);
}

void	collision(t_game *game, int new_x, int new_y)
{
	int		pos;

	if (collision_check(new_x, new_y, game->texture->wall_img->instances,
			game->texture->wall_img->count))
	{
		game->texture->player_img->instances[0].x = new_x;
		game->texture->player_img->instances[0].y = new_y;
	}
	pos = collision_collect(new_x, new_y, game->texture->collect_img->instances,
			game->texture->collect_img->count);
	if (pos != -1)
	{
		game->texture->collect_img->instances[pos].x = -100;
		game->texture->collect_img->instances[pos].enabled = false;
		game->collect--;
	}
	if (game->collect == 0)
		sprite_animation_door(*game);
	if (!collision_check(new_x, new_y, game->texture->exit_img->instances, 1)
		&& game->collect <= 0)
		mlx_close_window(game->mlx);
	if (!collision_check(new_x, new_y, game->texture->enemy_img->instances,
			game->texture->enemy_img->count))
		mlx_close_window(game->mlx);
}

int	display_images(mlx_t *mlx, t_texture *tx, t_map_info *map_info, int flag)
{
	int	i;
	int	j;

	i = -1;
	flag = 0;
	while (++i < map_info->lines)
	{
		j = -1;
		while (++j < map_info->rows)
		{
			if (map_info->map[i][j] == '1')
				flag = mlx_image_to_window(mlx, tx->wall_img, j * T, i * T);
			else if (map_info->map[i][j] == 'C')
				flag = mlx_image_to_window(mlx, tx->collect_img, j * T, i * T);
			else if (map_info->map[i][j] == 'P')
				flag = mlx_image_to_window(mlx, tx->player_img, j * T, i * T);
			else if (map_info->map[i][j] == 'E')
				flag = mlx_image_to_window(mlx, tx->exit_img, j * T, i * T);
			else if (map_info->map[i][j] == 'X')
				flag = mlx_image_to_window(mlx, tx->enemy_img, j * T, i * T);
		}
		if (flag == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	display_frame(char *map_path, t_map_info *map_info)
{
	t_game	game;

	file_to_matrix(map_path, map_info);
	game.mlx = mlx_init(map_info->rows * T, map_info->lines * T, TITLE, true);
	if (!game.mlx)
		fail_exit(map_info->map, game.mlx);
	game.texture = (t_texture *) malloc(sizeof(t_texture));
	if (!game.texture)
		fail_exit(map_info->map, game.mlx);
	if (init_textures(game.texture) || init_images(game.texture, game.mlx))
	{
		ft_putstr_fd("Error\nFail to load (texture\\image)\n", 2);
		exit_safe(game);
	}
	if (display_images(game.mlx, game.texture, map_info, 0))
		exit_safe(game);
	init_game(&game, *map_info);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_close_hook(game.mlx, close_button_handler, &game);
	mlx_loop(game.mlx);
	exit_safe(game);
	mlx_terminate(game.mlx);
}
