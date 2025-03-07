/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:29:28 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/07 00:55:29 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	print_steps(int *steps_counter)
{
	ft_putstr_fd("steps: ", 1);
	ft_putnbr(*steps_counter);
	ft_putchar('\n');
	(*steps_counter)++;
	return (5);
}
