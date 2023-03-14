/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:49:33 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/16 10:44:39 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putusnbr(unsigned int n)
{
	if (n < 10)
		ft_putchar_count(n + '0', 1);
	else
	{
		ft_putusnbr(n / 10);
		ft_putusnbr(n % 10);
	}
}

int	ft_putusnbr_count(unsigned int n, int counter)
{
	long long	i;

	i = 0;
	ft_putusnbr(n);
	if (n == 0)
		return (counter + 1);
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
