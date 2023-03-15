/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:39:26 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/15 16:06:35 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	sendable = 0;

void	char_decoder(int pid, unsigned char c)
{
	int	i;
	unsigned char chr;

	i = 7;
	chr = 1u<<i;
	while (chr)
	{
		sendable = 0;
		if (chr && c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (!sendable)
			pause();
		i--;
		chr >>= 1;
	}
}

void	send_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_decoder(pid, str[i]);
		i++;
	}
	char_decoder(pid, 0);
}

void	handler(int signal, siginfo_t *client, void *ucontext)
{
	(void) ucontext;
	if (signal == SIGUSR1)
		sendable = 1;
	else if (signal == SIGUSR2)
	{
		ft_printf("Message recieved from server side\n");
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char **argv)
{
	struct	sigaction	sig;
	int					pid;

	pid = 0;
	if (argc != 3)
	{
		ft_printf("Do ./client pid 'message'\n");
		exit(EXIT_FAILURE);
	}
	sig.sa_flags = SA_SIGINFO |  SA_RESTART;
	sig.sa_handler = (void (*)(int))handler;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("Valid pid pls\n");
		exit(EXIT_FAILURE);
	}
	send_string(pid, argv[2]);
	return (0);
}