/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:24:03 by kakumar           #+#    #+#             */
/*   Updated: 2022/12/06 12:18:19 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen((char *) s1);
	len2 = ft_strlen((char *) s2);
	i = 0;
	joined = (char *) malloc (sizeof(char) * (len1 + len2 + 1));
	if (joined == NULL)
		return (NULL);
	while (len1-- > 0)
		joined[i++] = *s1++;
	while (len2-- > 0)
		joined[i++] = *s2++;
	joined[i] = '\0';
	return (joined);
}
