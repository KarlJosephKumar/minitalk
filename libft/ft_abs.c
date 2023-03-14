/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:24:39 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/28 10:57:50 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_abs_plus(long a, long b)
{
	long	answer;

	answer = a + b;
	if (answer < 0)
		return (answer *= -1);
	else
		return (answer);
}

long	ft_abs_minus(long a, long b)
{
	long	answer;

	answer = a - b;
	if (answer < 0)
		return (answer *= -1);
	else
		return (answer);
}

long	ft_abs_mult(long a, long b)
{
	long	answer;

	answer = a * b;
	if (answer < 0)
		return (answer *= -1);
	else
		return (answer);
}

long	ft_abs_div(long a, long b)
{
	long	answer;

	answer = a / b;
	if (answer < 0)
		return (answer *= -1);
	else
		return (answer);
}

long	ft_abs(long a, long b, char c)
{
	if (c == '-')
		return (ft_abs_minus(a, b));
	else if (c == '+')
		return (ft_abs_plus(a, b));
	else if (c == '/')
		return (ft_abs_div(a, b));
	else if (c == '*')
		return (ft_abs_mult(a, b));
	else
		return (0);
}
