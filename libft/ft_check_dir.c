/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:38:09 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/07 15:52:27 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int	ft_check_dir(char *filename)
{
	int		fd;
	char	c[1];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (fd > -1)
	{
		c[0] = read(fd, c, 1);
		if (c[0] == -1)
		{
			close(fd);
			return (-1);
		}
	}
	return (0);
}
