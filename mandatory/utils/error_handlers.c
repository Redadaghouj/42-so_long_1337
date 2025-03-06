/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:18:46 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/06 02:37:38 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_msg(char *msg)
{
	write(STD_ERROR, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	free_map_and_exit(char **map, char *msg)
{
	free_buffer(map);
	exit_msg(msg);
}

void	ft_mlx_error(mlx_t *mlx)
{
	ft_putstr_fd("Error\n", STD_ERROR);
	mlx_terminate(mlx);
	exit(EXIT_FAILURE);
}

void	exit_safe(t_game *game)
{
	free_buffer(game->map);
	free_textures(game->texture);
	free_images(game->texture, game->mlx);
	mlx_close_window(game->mlx);
}
