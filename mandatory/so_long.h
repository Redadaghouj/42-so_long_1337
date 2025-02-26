/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:22:59 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/26 22:17:14 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> // -REMOVE-
# include "../MLX42/MLX42.h"
# include "gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 500
# define HEIGHT 500
# define EXIT_FAILURE 1
# define STD_ERROR 2
# define GAME_TITLE "AOT"

typedef struct s_map_info
{
	int	exit_count;
	int	player_count;
	int	collectible_count;
	int	is_closed;
	int	line_count;
	int	is_path_valid;
}				t_map_info;

/* UTILS */
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
/* SO_LONG_UTILS */
void	*free_buffer(char **buffer);
void	init_map_info(t_map_info *map_info);
/* VALIDATE MAP */
void	validate_map(char *map);
void	count_characters(t_map_info *map_info, char *line);
void	check_characters(t_map_info map_info);
void	validate_map(char *map_path);
int		is_not_closed(char **map, int size);
/* CHECK WALLS */
int		check_upper_wall(char **map);
int		check_lower_wall(char **map, int size);
int		check_left_wall(char **map, int size);
int		check_right_wall(char **map, int size);
/* ERROR HANDLERS */
void	exit_msg(char *msg);
void	free_map_and_exit(char **map, char *msg);

#endif
