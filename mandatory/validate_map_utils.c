/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:15:28 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/28 14:02:51 by mdaghouj         ###   ########.fr       */
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
		return (1);
	return (0);
}

void	flood_fill(char **map, int x, int y, t_map_info *map_info)
{
	if (x < 0 || x >= map_info->lines || y < 0 || y >= map_info->rows)
		return ;
	if (map[x][y] != 'E' || map[x][y] != 'C')
		return ;
	if (map[x][y] == 'E')
		map_info->exit_count--;
	if (map[x][y] == 'C')
		map_info->collectible_count--;
	map[x][y] = '0';
	flood_fill(map, x - 1, y, map_info);
	flood_fill(map, x + 1, y, map_info);
	flood_fill(map, x, y - 1, map_info);
	flood_fill(map, x, y + 1, map_info);
}

int	is_not_valid_path(char **map, t_map_info *map_info)
{
	int	x;
	int	y;

	x = 2, y = 2;
	flood_fill(map, x, y, map_info);
	return (0);
}

char	**file_to_matrix(char *map_path, int len)
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
		map[i] = line;
		if (!map[i++])
			free_map_and_exit(map, "Error\nMalloc failed.\n");
		line = get_next_line(fd);
	}
	close(fd);
	map[i] = NULL;
	return (map);
}
