/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:29:56 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/26 22:22:41 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		exit_msg("Error\nThe map is not rectangular.\n");
	}
}

void	file_to_matrix(char *map_path, int len)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = (char **) malloc(sizeof(char *) * (len + 1));
	if (!map)
		exit_msg("Error\nMalloc failed.\n");
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_msg("Error\nFile open failed.\n");
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		if (!map[i-1])
			free_map_and_exit(map, "Error\nMalloc failed.\n");
		line = get_next_line(fd);
	}
	close(fd);
	map[i] = NULL;
	if (is_not_closed(map, len - 1))
		free_map_and_exit(map, "Error\nMap not closed.\n");
}

int	is_not_closed(char **map, int size)
{
	if (check_upper_wall(map))
		return (1);
	else if (check_lower_wall(map, size))
		return (1);
	else if (check_left_wall(map, size))
		return (1);
	else if (check_right_wall(map, size))
		return (1);
	return (0);
}

void	validate_map(char *map_path)
{
	t_map_info	map_info;
	int			fd;
	char		*line;
	int			len;

	len = 0;
	init_map_info(&map_info);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_msg("Error\nFile open fail");
	line = get_next_line(fd);
	map_info.line_count = ft_strlen(line);
	while (line)
	{
		len++;
		count_characters(&map_info, line);
		check_rectangle(map_info.line_count, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_characters(map_info);
	file_to_matrix(map_path, len);
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
	The map must be rectangular ✅
	The extension must be .ber ✅
	The map must be closed/surrounded by wall ✅
	check if there’s a valid path in the map
*/