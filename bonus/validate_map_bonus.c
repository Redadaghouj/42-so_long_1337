/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:29:56 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/08 17:26:20 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_characters(t_map_info *map_info, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			map_info->collectibles++;
		else if (line[i] == 'E')
			map_info->exit++;
		else if (line[i] == 'P')
			map_info->player++;
		else if (line[i] == 'X')
			map_info->enemy++;
		else if (line[i] != '0' && line[i] != '1')
			map_info->wrong_chars = 1;
		i++;
	}
}

void	check_characters(t_map_info map_info)
{
	if (map_info.collectibles <= 0)
		exit_msg("Error\nInvalid number of collectibles.\n");
	if (map_info.exit <= 0 || map_info.exit > 1)
		exit_msg("Error\nInvalid number of exit.\n");
	if (map_info.player <= 0 || map_info.player > 1)
		exit_msg("Error\nInvalid number of player.\n");
	if (map_info.enemy <= 0 || map_info.enemy > 3)
		exit_msg("Error\nInvalid number of enemy.\n");
	if (map_info.wrong_chars)
		exit_msg("Error\nInvalid character.\n");
}

void	check_rectangle(int first_line, char *line)
{
	if (first_line != ft_strlen(line))
	{
		free(line);
		line = NULL;
		exit_msg("Error\nNo rectangular.\n");
	}
}

int	is_not_closed(char **map, int size)
{
	if (check_upper_wall(map))
		return (EXIT_FAILURE);
	else if (check_lower_wall(map, size))
		return (EXIT_FAILURE);
	else if (check_left_wall(map, size))
		return (EXIT_FAILURE);
	else if (check_right_wall(map, size))
		return (EXIT_FAILURE);
	return (0);
}

void	validate_map(char *map_path, t_map_info *map_info, t_player *player)
{
	int			fd;
	char		*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_msg("Error\nFile open fail");
	line = get_next_line(fd);
	map_info->rows = ft_strlen(line);
	while (line)
	{
		map_info->lines++;
		count_characters(map_info, line);
		check_rectangle(map_info->rows, line);
		check_player_position(player, map_info->lines - 1, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_window(map_info->lines, map_info->rows);
	check_characters(*map_info);
}
