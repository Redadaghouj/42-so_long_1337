/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:22:59 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/02/20 21:09:24 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 500
# define HEIGHT 500
# define EXIT_FAILURE 1
# define STD_ERROR 2

/* UTILS */
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(const char *s);
void	ft_draw_line(mlx_image_t* image, int x1, int y1, int x2, int y2, uint32_t color);

#endif
