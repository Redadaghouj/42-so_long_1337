/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:29:56 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/26 16:27:41 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_info(t_map_info *map_info)
{
	map_info->collectible_count = 0;
	map_info->exit_count = 0;
	map_info->is_closed = 0;
	map_info->is_path_valid = 0;
	map_info->is_rectangle = 0;
	map_info->player_count = 0;
}

void	count_characters(t_map_info *map_info, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			map_info->collectible_count++;
		else if (line[i] == 'E')
			map_info->exit_count++;
		else if (line[i] == 'P')
			map_info->player_count++;
		i++;
	}
}

void	check_characters(t_map_info map_info)
{
	if (map_info.collectible_count <= 0)
		exit_msg("Error\nInvalid number of collectibles.\n");
	if (map_info.exit_count <= 0 || map_info.exit_count > 1)
		exit_msg("Error\nInvalid number of exits.\n");
	if (map_info.player_count <= 0 || map_info.player_count > 1)
		exit_msg("Error\nInvalid number of players.\n");
}

void	check_rectangle(int first_line, char *line)
{
	if (first_line != ft_strlen(line))
	{
		free(line);
		line = NULL;
		exit_msg("Error\nInvalid grid, The map is not rectangular.\n");
	}
}

void	check_map_structure(t_map_info map_info, char *line)
{
	check_rectangle(map_info.is_rectangle, line);
	// check_walls();
}

void	validate_map(char *map_path)
{
	t_map_info	map_info;
	int			fd;
	char		*line;

	init_map_info(&map_info);
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	map_info.is_rectangle = ft_strlen(line);
	while (line != NULL)
	{
		count_characters(&map_info, line);
		check_map_structure(map_info, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_characters(map_info);
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
	The map must be rectangular
	The map must be closed/surrounded by wall
	check if there’s a valid path in the map
*/