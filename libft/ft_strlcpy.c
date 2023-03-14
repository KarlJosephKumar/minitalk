/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:22:47 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/08 10:38:08 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*des;
	unsigned char	*source;
	size_t			j;
	int				i;
	int				k;

	i = 0;
	des = (unsigned char *) dst;
	source = (unsigned char *) src;
	j = ft_strlen((char *) source);
	k = ft_strlen((char *) dst + 1);
	if (dstsize == 0 || src == NULL)
		return (ft_strlen((char *) source));
	while (j > 0 && source[i] != '\0' && dstsize-- > 1)
	{
		des[i] = source[i];
		i++;
		j--;
	}
	des[i] = '\0';
	return (ft_strlen((char *)source));
}
