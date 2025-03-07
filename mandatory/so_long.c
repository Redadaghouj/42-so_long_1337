/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:52 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/07 02:28:11 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_buffer(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	return (NULL);
}

void	close_button_handler(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_close_window(game->mlx);
}

void	init_map_info(t_map_info *map_info)
{
	map_info->map = NULL;
	map_info->collectibles = 0;
	map_info->exit = 0;
	map_info->path_checker = 0;
	map_info->player = 0;
	map_info->lines = 0;
	map_info->rows = 0;
}

void	run_validate_map(char *map_path, t_player *player, t_map_info *map_info)
{
	if (is_wrong_ext(map_path))
		exit_msg("Error\nInvalid file extension.\n");
	init_map_info(map_info);
	validate_map(map_path, map_info, player);
	file_to_matrix(map_path, map_info);
	if (is_not_closed(map_info->map, map_info->lines - 1))
		free_map_and_exit(map_info->map, "Error\nMap not closed.\n");
	if (is_not_valid_path(map_info, *player))
		free_map_and_exit(map_info->map, "Error\nMap path is not valid.\n");
	free_buffer(map_info->map);
}

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	t_player	player;

	if (argc != 2)
		return (EXIT_FAILURE);
	run_validate_map(argv[1], &player, &map_info);
	display_frame(argv[1], &map_info);
	return (EXIT_SUCCESS);
}
