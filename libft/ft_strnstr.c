/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:49:50 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:42 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_finder(const char *haystack, const char *needle, size_t len)
{
	while (*needle == *haystack && *needle != 0 && len > 0)
	{
		len--;
		haystack++;
		needle++;
	}
	if (*needle == 0)
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == 0)
		return ((char *) haystack);
	while (len > 0 && *haystack != 0)
	{
		if (str_finder(haystack, needle, len))
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (0);
}
