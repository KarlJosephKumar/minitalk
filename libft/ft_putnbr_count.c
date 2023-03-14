/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:46:38 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/16 10:51:54 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_minint(long n)
{
	if (n < 0)
	{
		ft_putchar_count('-', 1);
		n *= -1;
	}
	if (n > 10)
		ft_minint(n / 10);
	if (n == 2147483647)
		ft_putchar_count('8', 1);
	else
		ft_putchar_count(n % 10 + '0', 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_minint(n);
	else
	{
		if (n < 0)
		{
			ft_putchar_count(('-'), 1);
			n *= -1;
		}
		if (n < 10)
			ft_putchar_count(n + '0', 1);
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}

int	ft_putnbr_count(int n, int counter)
{
	int	i;

	i = 0;
	ft_putnbr(n);
	if (n == 0)
		return (counter + 1);
	if (n == -2147483648)
		return (counter + 11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (counter + i);
}
