/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:02:42 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/04 16:43:48 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_join(char *buff, char *holder)
{
	char	*temp;
	int		i;

	i = 0;
	if (!holder)
		holder = ft_calloc(1, 1);
	temp = ft_strjoin(holder, buff);
	free(holder);
	return (temp);
}

char	*update_holder(t_variable var, char *holder)
{
	if (var.ret == NULL)
	{
		free(holder);
		return (NULL);
	}
	var.k = slen(holder);
	var.i = 0;
	while (holder[var.i] != '\n' && var.i < var.k)
		var.i++;
	if (holder[var.i] == '\n')
		var.i++;
	var.temp = ft_calloc(slen(holder) + 1, sizeof(char));
	if (!var.temp)
		return (NULL);
	while (holder[var.i] != '\0')
		var.temp[var.j++] = holder[var.i++];
	var.temp[var.j] = '\0';
	free(holder);
	return (var.temp);
}

char	*get_line(t_variable var, char *holder)
{
	var.i = 0;
	var.j = 0;
	if (holder[var.i] == '\0')
		return (NULL);
	while (holder[var.i] != '\0')
	{
		if (holder[var.i] == '\n')
		{
			var.ret = (char *) malloc (sizeof(char) * var.i + 2);
			if (!var.ret)
			{
				free(holder);
				return (NULL);
			}
			while (holder[var.j] != '\n')
				var.ret[var.j++] = holder[var.j];
			var.ret[var.j++] = '\n';
			var.ret[var.j] = '\0';
			return (var.ret);
		}
		var.i++;
	}
	return (var.ret);
}

char	*read_buffer(int fd, t_variable var, char *holder)
{
	var.bytes = 1;
	var.buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (var.buff == NULL)
		return (NULL);
	while (var.bytes > 0)
	{
		var.bytes = read(fd, var.buff, BUFFER_SIZE);
		if (var.bytes < 0)
		{
			free(var.buff);
			return (NULL);
		}
		var.buff[var.bytes] = '\0';
		if (ft_strchr(var.buff, '\n') == NULL)
			holder = ft_join(var.buff, holder);
		else
		{
			holder = ft_join(var.buff, holder);
			break ;
		}
	}
	free(var.buff);
	return (holder);
}

char	*get_next_line(int fd)
{
	t_variable	var;
	static char	*holder;

	var.i = 0;
	var.j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	holder = read_buffer(fd, var, holder);
	if (!holder)
		return (NULL);
	if (holder[var.i] != '\0' && holder && ft_strchr(holder, '\n') == NULL)
	{
		var.ret = ft_calloc(slen(holder) + 1, sizeof(char));
		var.ret = ft_join(holder, var.ret);
		holder = update_holder(var, holder);
		return (var.ret);
	}
	else
		var.ret = get_line(var, holder);
	holder = update_holder(var, holder);
	return (var.ret);
}
