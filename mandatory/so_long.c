/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:52 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/21 13:27:33 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*image;

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
		image->instances[0].x += 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
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

	mlx = mlx_init(WIDTH, HEIGHT, "Game", false);
	if (!mlx)
		ft_mlx_error(mlx);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		ft_mlx_error(mlx);
	ft_draw_square(image);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
