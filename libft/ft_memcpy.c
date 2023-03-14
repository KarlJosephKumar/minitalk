/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:48:33 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/09 10:27:56 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*srcz;
	char	*dstz;

	if (src == NULL && dst == NULL)
		return (NULL);
	srcz = (char *) src;
	dstz = dst;
	while (n-- > 0)
		*dstz++ = *srcz++;
	return (dst);
}
