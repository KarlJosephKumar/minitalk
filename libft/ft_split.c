/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:53:50 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/01 12:17:32 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	words(char const *s, char c)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
		{
			i++;
			if (s[i] == 0)
				j--;
		}
		while (s[i] != c && s[i] != 0)
			i++;
		j++;
	}
	return (j);
}

static int	letters(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**splitter(char **strs, char c, char const *s, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0' && k > i)
	{
		while (*s == c && *s)
			s++;
		j = 0;
		strs[i] = (char *) malloc (sizeof(char) * letters(s, c) + 1);
		if (strs[i] == NULL)
		{
			while (i >= 0)
				free(strs[i--]);
			free(strs);
			return (NULL);
		}
		ft_strlcpy(strs[i++], s, letters(s, c) + 1);
		while (*s != c && *s != '\0')
			s++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		k;

	if (s == NULL)
		return (NULL);
	k = words(s, c);
	strs = (char **) malloc (sizeof(char *) * (k + 1));
	if (strs == NULL)
		return (NULL);
	strs[k] = NULL;
	strs = splitter(strs, c, s, k);
	return (strs);
}
