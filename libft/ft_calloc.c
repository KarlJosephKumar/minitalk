/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:13:12 by kakumar           #+#    #+#             */
/*   Updated: 2022/12/19 10:40:41 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*a;
	size_t			bytes;
	size_t			i;

	i = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	bytes = count * size;
	ptr = malloc(bytes);
	a = (unsigned char *) ptr;
	if (ptr != NULL)
	{
		while (i < bytes)
			a[i++] = 0;
	}
	return (a);
}
