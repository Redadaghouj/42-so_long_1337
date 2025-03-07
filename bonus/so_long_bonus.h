/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:22:59 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/07 01:34:02 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h> // -REMOVE-
# include "../MLX42/MLX42.h"
# include "gnl_bonus/get_next_line_bonus.h"
# include <unistd.h>
# include <stdlib.h>

# define T 64
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define STD_ERROR 2
# define TITLE "PAC MAN"

typedef struct s_map_info
{
	char	**map;
	int		exit;
	int		player;
	int		collectibles;
	int		path_checker;
	int		rows;
	int		lines;
}				t_map_info;

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_texture
{
	mlx_texture_t	*bg;
	mlx_image_t		*bg_img;
	mlx_texture_t	*wall;
	mlx_image_t		*wall_img;
	mlx_texture_t	*player;
	mlx_image_t		*player_img;
	mlx_texture_t	*collect;
	mlx_image_t		*collect_img;
	mlx_texture_t	*exit;
	mlx_image_t		*exit_img;
}				t_texture;

typedef struct s_game
{
	mlx_t			*mlx;
	t_texture		*texture;
	int				collect;
	char			**map;
	int				steps_counter;
}				t_game;

/* SO_LONG */
void	*free_buffer(char **buffer);
/* UTILS */
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(int c);
/* VALIDATE MAP */
void	validate_map(char *map_path, t_map_info *map_info, t_player *player);
int		is_not_closed(char **map, int size);
void	count_characters(t_map_info *map_info, char *line);
void	check_characters(t_map_info map_info);
/* VALIDATE MAP UTILS */
void	file_to_matrix(char *map_path, t_map_info *map_info);
int		is_wrong_ext(char *filename);
int		is_not_valid_path(t_map_info *map_info, t_player player);
void	check_player_position(t_player *player, int line_num, char *line);
/* CHECK WALLS */
int		check_upper_wall(char **map);
int		check_lower_wall(char **map, int size);
int		check_left_wall(char **map, int size);
int		check_right_wall(char **map, int size);
/* ERROR HANDLERS */
void	exit_msg(char *msg);
void	free_map_and_exit(char **map, char *msg);
void	ft_mlx_error(mlx_t *mlx);
void	exit_safe(t_game game);
void	fail_exit(char **map, mlx_t *mlx);
/* DISPLAY FRAME */
void	display_frame(char *map_path, t_map_info *map_info);
void	collision(t_game *game, int new_x, int new_y);
/* DISPLAY FRAME UTILS */
int		init_textures(t_texture *texture);
int		init_images(t_texture *texture, mlx_t *mlx);
int		collision_check(int p_x, int p_y, mlx_instance_t *wall, int len);
int		collision_collect(int p_x, int p_y, mlx_instance_t *coin, int len);
void	free_textures(t_texture *texture);
void	free_images(t_texture *texture, mlx_t *mlx);
void	close_button_handler(void *param);
/* PRINT STEPS */
int		print_steps(int *steps_counter);

#endif
