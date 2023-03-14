/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:34:47 by kakumar           #+#    #+#             */
/*   Updated: 2022/12/17 15:02:09 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;
	int		len;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
		i++;
	while (ft_strrchr(set, s1[len]) != NULL && s1[i])
		len--;
	len = len - i + 1;
	trim = (char *) malloc (sizeof(char) * len + 1);
	if (!trim)
		return (NULL);
	while (len-- > 0)
		trim[j++] = s1[i++];
	trim[j] = '\0';
	return (trim);
}
