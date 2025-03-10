/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:20:44 by mdaghouj          #+#    #+#             */
/*   Updated: 2025/03/08 01:17:47 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*src_ptr;

	ptr = (unsigned char *) dest;
	src_ptr = (unsigned char *) src;
	while (n > 0)
	{
		*ptr = *src_ptr;
		ptr++;
		src_ptr++;
		n--;
	}
}
