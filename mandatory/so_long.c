/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:52 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/01 21:05:54 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_validation_map(char *map_path, t_player *player)
{
	t_map_info	map_info;

	if (is_wrong_ext(map_path))
		exit_msg("Error\nInvalid file extension.\n");
	init_map_info(&map_info);
	init_player(player);
	validate_map(map_path, &map_info, player);
	file_to_matrix(map_path, &map_info);
	if (is_not_closed(map_info.map, map_info.lines - 1))
		free_map_and_exit(map_info.map, "Error\nMap not closed.\n");
	if (is_not_valid_path(&map_info, *player))
		free_map_and_exit(map_info.map, "Error\nMap path is not valid.\n");
	free_buffer(map_info.map);
}

int	main(int argc, char *argv[])
{
	t_player	player;

	if (argc != 2)
		return (EXIT_FAILURE);
	run_validation_map(argv[1], &player);
	display_frame(argv[1], player);
	return (EXIT_SUCCESS);
}
