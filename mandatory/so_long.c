/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:52 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/21 10:43:32 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int square_x = 200;
int square_y = 200;

void	ft_mlx_error(mlx_t *mlx)
{
	ft_putstr_fd("Error\n", STD_ERROR);
	mlx_terminate(mlx);
	exit(EXIT_FAILURE);
}

void	key_hook(mlx_key_data_t key_data, void *param)
{
	if (key_data.action == MLX_PRESS)
	{
		if (key_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(param);
		else if (key_data.key == MLX_KEY_RIGHT)
			puts("RIGHT");		
		else if (key_data.key == MLX_KEY_LEFT)
			puts("LEFT");		
		else if (key_data.key == MLX_KEY_UP)
			puts("UP");		
		else if (key_data.key == MLX_KEY_DOWN)
			puts("DOWN");		
	}
}

void	ft_draw_square(mlx_image_t *image)
{
	int	x = 200;
	int	y = 200;
	while (y < HEIGHT - 200)
	{
		x = 200;
		while (x < WIDTH - 200)
		{
			mlx_put_pixel(image, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(WIDTH, HEIGHT, "Game", false);
	if (!mlx)
		ft_mlx_error(mlx);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		ft_mlx_error(mlx);
	ft_draw_square(image);
	mlx_key_hook(mlx, key_hook, mlx);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
