/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:46:53 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/08 15:11:39 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	positive_num(const char *str)
{
	int			result;
	long long	rslt;

	rslt = 0;
	result = 0;
	while (*str >= 48 && *str <= 57)
	{
		result *= 10;
		result += *str - 48;
		rslt *= 10;
		rslt += *str -48;
		str++;
		if (rslt < 0)
			return (-1);
	}
	return (result);
}

int	negative_num(const char *str)
{
	int			result;
	long long	rslt;

	rslt = 0;
	result = 0;
	while (*str >= 48 && *str <= 57)
	{
		result *= 10;
		result -= *str - 48;
		rslt *= 10;
		rslt -= *str -48;
		str++;
		if (rslt > 0)
			return (0);
	}
	return (result);
}

int	ft_atoi(const char *str)
	{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		str++;
		return (negative_num((char *)str));
	}
	else if (*str == '+')
	{
		str++;
		return (positive_num((char *)str));
	}
	else
	{
		return (positive_num((char *)str));
	}
}
