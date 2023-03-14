/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:58:34 by kakumar           #+#    #+#             */
/*   Updated: 2022/12/16 15:04:59 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	slen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	a = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return ((char *)&s[i]);
		i++;
	}
	if (a == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = slen(s1);
	len2 = slen(s2);
	joined = (char *) malloc (sizeof(char) * (len1 + len2 + 1));
	if (joined == NULL)
		return (NULL);
	while (len1-- > 0)
	{
		joined[i] = s1[i];
		i++;
	}
	while (len2-- > 0)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

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
