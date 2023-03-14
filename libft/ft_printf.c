/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:10:29 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/18 09:24:59 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	typechecker(const char *input, int counter, va_list args, int i)
{
	input++;
	if (*input == 'c')
		i = ft_putchar_count(va_arg(args, int), counter);
	if (*input == 's')
		i = ft_putstr_count(va_arg(args, char *), counter);
	if (*input == 'p')
		i = ft_putpointer_count((uintptr_t)va_arg(args, void *), counter);
	if (*input == 'd')
		i = ft_putnbr_count(va_arg(args, int), counter);
	if (*input == 'i')
		i = ft_putnbr_count(va_arg(args, int), counter);
	if (*input == 'u')
		i = ft_putusnbr_count(va_arg(args, int), counter);
	if (*input == 'x')
		i = ft_putlohex_count(va_arg(args, unsigned int), counter);
	if (*input == 'X')
		i = ft_putuphex_count(va_arg(args, unsigned int), counter);
	if (*input == '%')
	{
		write(1, &(*input), 1);
		i = counter + 1;
		input++;
	}
	return (i);
}

static int	numberofchars(const char *input, va_list args)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (*input)
	{
		if (*input == '%')
		{
			counter = typechecker(input, counter, args, i);
			input += 2;
		}
		if (*input != '%' && *input)
		{
			ft_putchar_count(*input, counter);
			input++;
			counter++;
		}
	}
	return (counter);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		ret;

	va_start(args, input);
	ret = numberofchars(input, args);
	va_end(args);
	return (ret);
}
