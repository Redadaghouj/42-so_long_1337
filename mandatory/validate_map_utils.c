/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:15:28 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/06 00:38:13 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wrong_ext(char *filename)
{
	char	*s;
	int		idx;

	s = ".ber";
	idx = ft_strlen(filename) - 4;
	if (ft_strcmp(s, &filename[idx]) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	flood_fill(t_map_info *map_info, int y, int x)
{
	if (y >= map_info->lines || x >= map_info->rows)
		return ;
	if (map_info->map[y][x] == '1' || map_info->map[y][x] == 'F')
		return ;
	if (map_info->map[y][x] == 'E' || map_info->map[y][x] == 'C')
		map_info->path_checker++;
	map_info->map[y][x] = 'F';
	flood_fill(map_info, y - 1, x);
	flood_fill(map_info, y + 1, x);
	flood_fill(map_info, y, x - 1);
	flood_fill(map_info, y, x + 1);
}

int	is_not_valid_path(t_map_info *map_info, t_player player)
{
	flood_fill(map_info, player.y, player.x);
	if (map_info->path_checker == (map_info->exit + map_info->collectibles))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	file_to_matrix(char *map_path, t_map_info *map_info)
{
	int		fd;
	char	*line;
	int		i;
	int		len;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_msg("Error\nFile open failed.\n");
	i = 0;
	len = map_info->lines;
	map_info->map = (char **) malloc(sizeof(char *) * (len + 1));
	if (!map_info->map)
		exit_msg("Error\nMalloc failed.\n");
	line = get_next_line(fd);
	while (line)
	{
		map_info->map[i] = line;
		if (!map_info->map[i++])
			free_map_and_exit(map_info->map, "Error\nMalloc failed.\n");
		line = get_next_line(fd);
	}
	close(fd);
	map_info->map[i] = NULL;
}

void	check_player_position(t_player *player, int line_num, char *line)
{
	int	i;

	if (player->x != -1)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			player->x = i;
			player->y = line_num;
			break ;
		}
		i++;
	}
}
