/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:10:59 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/16 10:50:38 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(char *s, int count)
{
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (count + 6);
	}
	while (*s)
	{
		write (1, &(*s), 1);
		count++;
		s++;
	}
	return (count);
}
