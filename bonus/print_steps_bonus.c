/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:29:28 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/08 02:21:39 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_digits(int n, int *sign)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
		*sign = 1;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	i = count_digits(n, &sign);
	str = (char *) malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (sign)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

void	print_steps(t_game *game)
{
	char	*steps;

	steps = ft_itoa(game->steps_counter);
	if (game->steps_text)
		mlx_delete_image(game->mlx, game->steps_text);
	game->steps_text = mlx_put_string(game->mlx, steps, 10, 30);
	game->steps_counter++;
	free(steps);
}
