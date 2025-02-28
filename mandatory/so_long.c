/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:52 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/28 13:21:08 by mdaghouj         ###   ########.fr       */
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
	char		**map;
	t_map_info	map_info;

	if (argc != 2)
		return (1);
	if (is_wrong_ext(argv[1]))
		exit_msg("Error\nInvalid file extension.\n");
	init_map_info(&map_info);
	validate_map(argv[1], &map_info);
	map = file_to_matrix(argv[1], map_info.lines);
	if (is_not_closed(map, map_info.lines - 1))
		free_map_and_exit(map, "Error\nMap not closed.\n");
	if (is_not_valid_path(map, &map_info))
		free_map_and_exit(map, "Error\nMap path is not valid.\n");
	return (0);
}

/*	FIX: validate map
----------------------
	0 for an empty space
	1 for wall
	C for collectible
	E for a map exit
	P for the player starting pos
	------------------------------
	1 exit ✅
	1 collectible ✅
	1 starting position ✅
	------------------------------
	The extension must be .ber ✅
	The map must be rectangular ✅
	The map must be closed/surrounded by wall
	check if there’s a valid path in the map
*/
