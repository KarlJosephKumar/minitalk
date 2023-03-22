/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:39:54 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/20 11:12:34 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static unsigned char	c;
	static int				counter;

	if (signal == SIGUSR1)
		c |= (1 << counter);
	counter++;
	if (counter == 8 && c)
	{
		write(1, &c, 1);
		c = 0x00;
		counter = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Pid: %i\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		usleep(20);
	return (0);
}
