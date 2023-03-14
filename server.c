/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:39:54 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/14 14:52:35 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client *client;

void	client_init(t_client *client)
{
	client = malloc(sizeof(t_client));
	client->bit_count = 0;
	client->c = 0;
	client->pid = 0;
}

void	handler(int signal, siginfo_t *server, void *ucontext)
{
	client->i = 0;
	client->c <<= 1;
	client->c += signal == SIGUSR1;
	if (++client->i == 8)
	{
		ft_printf("%c", client->c);
		client->i = 0;
		client->c = 0;
	}
}

int	main(void)
{
	client_init(client);
	client->sig.sa_flags = SA_RESTART | SA_SIGINFO;
	client->sig.sa_handler = handler;
	sigemptyset(&client->sig.sa_mask);
	sigaction(SIGUSR1, &client->sig, NULL);
	sigaction(SIGUSR2, &client->sig, NULL);
	client->pid = getpid();
	ft_printf("Pid: %i\n", client->pid);
	free(client);
	return (0);
}