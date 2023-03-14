/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:31:53 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/08 15:16:44 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destin;
	unsigned char	*source;
	int				i;

	i = 0;
	destin = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (destin > source)
	{
		while (len-- > 0)
			destin[len] = source[len];
	}
	else
	{
		while (len-- > 0)
		{
			destin[i] = source[i];
			i++;
		}
	}
	return (dst);
}
