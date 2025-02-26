/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:52 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/26 16:36:33 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*img;

void	ft_mlx_error(mlx_t *mlx)
{
	ft_putstr_fd("Error\n", STD_ERROR);
	mlx_terminate(mlx);
	exit(EXIT_FAILURE);
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *) param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 5;
}

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

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	if (is_wrong_ext(argv[1]))
		exit_msg("Error\nInvalid file extension.\n");
	validate_map(argv[1]);
	return (0);
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
	The extension must be .ber ✅
	The map must be rectangular ✅
	The map must be closed/surrounded by wall
	check if there’s a valid path in the map
*/
