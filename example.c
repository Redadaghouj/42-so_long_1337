/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:52 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/26 11:04:21 by mdaghouj         ###   ########.fr       */
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
	mlx_t	*mlx = param;
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

// void	ft_draw_square(mlx_image_t *img)
// {
// 	int	x = 200;
// 	int	y = 200;
// 	while (y < HEIGHT - 200)
// 	{
// 		x = 200;
// 		while (x < WIDTH - 200)
// 		{
// 			mlx_put_pixel(img, x, y, 0xFFFFFF);
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;

	mlx = mlx_init(WIDTH, HEIGHT, "AOT", false);
	if (!mlx)
		ft_mlx_error(mlx);
	texture = mlx_load_png("mandatory/images/stand_eren.png");
	if (!texture)
		ft_mlx_error(mlx);
	img = mlx_texture_to_image(mlx, texture);
	// img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		ft_mlx_error(mlx);
	// ft_draw_square(img);
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		ft_mlx_error(mlx);
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
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
	1 exit
	1 collectible
	1 starting position
	------------------------------
	The map must be rectangular
	The map must be closed/surrounded by wall
	check if there’s a valid path in the map
*/