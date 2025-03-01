/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:22:59 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/01 18:23:44 by mdaghouj         ###   ########.fr       */
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
# define EXIT_SUCCESS 0
# define STD_ERROR 2
# define GAME_TITLE "AOT"

typedef struct s_map_info
{
	char	**map;
	int		exit;
	int		player;
	int		collectibles;
	int		path_checker;
	int 	rows;
	int 	lines;
}				t_map_info;

typedef struct	s_player
{
	int x;
	int y;
}				t_player;

/* UTILS */
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
/* SO_LONG_UTILS */
void	*free_buffer(char **buffer);
void	init_map_info(t_map_info *map_info);
/* VALIDATE MAP */
void	validate_map(char *map_path, t_map_info *map_info, t_player *player);
int		is_not_closed(char **map, int size);
void	count_characters(t_map_info *map_info, char *line);
void	check_characters(t_map_info map_info);
/* VALIDATE MAP UTILS */
void	file_to_matrix(char *map_path, t_map_info *map_info);
int		is_wrong_ext(char *filename);
int		is_not_valid_path(t_map_info *map_info, t_player player);
/* CHECK WALLS */
int		check_upper_wall(char **map);
int		check_lower_wall(char **map, int size);
int		check_left_wall(char **map, int size);
int		check_right_wall(char **map, int size);
/* ERROR HANDLERS */
void	exit_msg(char *msg);
void	free_map_and_exit(char **map, char *msg);
void	ft_mlx_error(mlx_t *mlx);
/* PLAYER */
void	check_player_position(t_player *player, int line_num, char *line);
void	init_player(t_player *player);

#endif
