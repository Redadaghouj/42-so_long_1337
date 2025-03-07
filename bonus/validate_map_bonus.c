/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:29:56 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/07 01:34:31 by mdaghouj         ###   ########.fr       */
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
		i++;
	}
}

void	check_characters(t_map_info map_info)
{
	if (map_info.collectibles <= 0)
		exit_msg("Error\nInvalid number of collectibles.\n");
	if (map_info.exit <= 0 || map_info.exit > 1)
		exit_msg("Error\nInvalid number of exits.\n");
	if (map_info.player <= 0 || map_info.player > 1)
		exit_msg("Error\nInvalid number of players.\n");
}

void	check_rectangle(int first_line, char *line)
{
	if (first_line != ft_strlen(line))
	{
		free(line);
		line = NULL;
		exit_msg("Error\nThe map is not rectangular.\n");
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
	check_characters(*map_info);
}
