/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:39:54 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/15 16:06:41 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *server, void *ucontext)
{
	(void) ucontext;
	static unsigned char c;
	static int	counter = -1;

	if (kill(server->si_pid, 0) < 0)
		exit(EXIT_FAILURE);
	if (counter < 0)
		counter = 7;
	if (signal == SIGUSR1)
		c |= (1 << counter);
	counter--;
	if (counter < 0 && c)
	{
		write(1, &c, 1);
		c = 0;
	}
	else if (counter < 0 && !c)
	{
		kill(server->si_pid, SIGUSR2);
	}
	kill(server->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;
	int					pid;

	sig.sa_flags = SA_SIGINFO |  SA_RESTART;
	sig.sa_handler = (void (*)(int))handler;
	sigemptyset(&sig.sa_mask);
	pid = getpid();
	ft_printf("Pid: %i\n", pid);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		sleep(1);
	return (0);
}
