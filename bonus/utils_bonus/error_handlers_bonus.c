/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:18:46 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/09 02:41:34 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void	fail_exit(char **map, mlx_t *mlx)
{
	free_buffer(map);
	ft_mlx_error(mlx);
}

void	ft_mlx_error(mlx_t *mlx)
{
	ft_putstr_fd("Error\n", STD_ERROR);
	mlx_terminate(mlx);
	exit(EXIT_FAILURE);
}

void	exit_safe(t_game game)
{
	if (game.map)
		free_buffer(game.map);
	if (game.texture)
	{
		free_textures(game.texture);
		free_images(game.texture, game.mlx);
		free(game.texture);
	}
	exit(EXIT_SUCCESS);
}
