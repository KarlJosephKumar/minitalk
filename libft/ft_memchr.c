/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:12:22 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/08 15:16:30 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	i;

	a = (unsigned char *) s;
	i = (unsigned char) c;
	while (n-- > 0)
	{
		if (*a == i)
			return (a);
		a++;
	}
	return (NULL);
}
