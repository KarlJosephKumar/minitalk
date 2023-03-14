/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:56:14 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/07 09:22:19 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*posstr(char *str, int numlength, int n)
{
	while (numlength >= 0)
	{
		str[numlength--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static char	*negstr(char *str, int numlength, long n)
{
	str[0] = '-';
	str[numlength + 1] = '\0';
	while (numlength > 0)
	{
		str[numlength--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static int	numlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		numlength;
	char	*str;

	numlength = numlen((long) n);
	if (n >= 0 || n == '+')
	{
		str = (char *) malloc (sizeof(char) * numlength + 1);
		if (str == NULL)
			return (NULL);
		str[numlength--] = '\0';
		str = posstr(str, numlength, n);
	}
	else
	{
		str = (char *) malloc (sizeof(char) * numlength + 2);
		if (str == NULL)
			return (NULL);
		str = negstr(str, numlength, ((long)n * -1));
	}
	return (str);
}
