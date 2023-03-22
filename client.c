/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:39:26 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/20 14:06:37 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_decoder(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			usleep(505);
			kill(pid, SIGUSR1);
		}
		else
		{
			usleep(520);
			kill(pid, SIGUSR2);
		}
		i++;
	}
}

void	send_string(int pid, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		char_decoder(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*str;

	pid = 0;
	if (argc != 3)
	{
		ft_printf("Do ./client pid 'message'\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) != 0 || !pid)
	{
		ft_printf("Invalid pid\n");
		exit(EXIT_FAILURE);
	}
	str = argv[2];
	if (*str == '\0')
	{
		ft_printf("Empty string is not allowed\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Starting to send message\n");
	send_string(pid, str);
	ft_printf("Message sent.\n");
	return (0);
}
