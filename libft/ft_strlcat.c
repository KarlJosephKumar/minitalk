/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:40:45 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/08 10:38:20 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*source;
	size_t			total;
	size_t			i;
	int				j;

	j = 0;
	if (dstsize == 0 && !dst)
		return (0);
	i = ft_strlen((char *) dst);
	source = (unsigned char *) src;
	total = ft_strlen((char *) src) + ft_strlen((char *) dst);
	if (dstsize > i)
	{
		while (source[j] != '\0' && i < dstsize - 1)
			dst[i++] = source[j++];
		dst[i] = '\0';
		return (total);
	}
	else if (ft_strlen((char *)dst) == 0)
		return (ft_strlen((char *)src));
	else
		return (ft_strlen((char *)src) + dstsize);
}
