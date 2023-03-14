/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlohex_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:51:56 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/18 09:25:15 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlohex(unsigned int n)
{
	unsigned long	i;
	int				k;
	char			hex[16];

	k = 0;
	while (n > 0 && k < 16)
	{
		i = n % 16;
		if (i < 10)
			i += 48;
		else
			i += 87;
		hex[k++] = i;
		n = n / 16;
	}
	while (k > 0)
	{
		k--;
		write(1, &hex[k], 1);
	}
}

int	ft_putlohex_count(unsigned int n, int counter)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (counter + 1);
	}
	ft_putlohex(n);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (counter + i);
}
