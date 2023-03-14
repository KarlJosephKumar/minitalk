/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:27:28 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/16 16:07:37 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(uintptr_t ptr)
{
	unsigned long	i;
	int				k;
	char			hex[16];

	k = 0;
	while (ptr > 0 && k < 16)
	{
		i = ptr % 16;
		if (i < 10)
			i += 48;
		else
			i += 87;
		hex[k++] = i;
		ptr = ptr / 16;
	}
	while (k > 0)
	{
		k--;
		write(1, &hex[k], 1);
	}
}

int	ft_putpointer_count(uintptr_t ptr, int counter)
{
	int	i;

	i = 0;
	write(1, "0", 1);
	write(1, "x", 1);
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (counter + 3);
	}
	ft_putpointer(ptr);
	while (ptr > 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (counter + i + 2);
}
