/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:51:42 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/01 17:47:34 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_upper_wall(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			return (EXIT_FAILURE);
			break ;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_lower_wall(char **map, int size)
{
	int	i;

	i = 0;
	while (map[size][i])
	{
		if (map[size][i] != '1')
		{
			return (EXIT_FAILURE);
			break ;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_left_wall(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map[i][0] != '1')
		{
			return (EXIT_FAILURE);
			break ;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_right_wall(char **map, int size)
{
	int	i;
	int	end;

	i = 0;
	end = ft_strlen(map[0]) - 1;
	while (i < size)
	{
		if (map[i][end] != '1')
		{
			return (EXIT_FAILURE);
			break ;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
