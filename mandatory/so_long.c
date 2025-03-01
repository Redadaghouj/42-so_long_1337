/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:52 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/01 18:24:05 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*img;

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *) param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 5;
}

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	t_player	player;

	if (argc != 2)
		return (EXIT_FAILURE);
	if (is_wrong_ext(argv[1]))
		exit_msg("Error\nInvalid file extension.\n");
	init_map_info(&map_info);
	init_player(&player);
	validate_map(argv[1], &map_info, &player);
	file_to_matrix(argv[1], &map_info);
	if (is_not_closed(map_info.map, map_info.lines - 1))
		free_map_and_exit(map_info.map, "Error\nMap not closed.\n");
	if (is_not_valid_path(&map_info, player))
		free_map_and_exit(map_info.map, "Error\nMap path is not valid.\n");
	return (EXIT_SUCCESS);
}
