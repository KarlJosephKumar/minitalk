/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:34:07 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/14 14:51:11 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <signal.h>

typedef struct	s_client
{
	struct sigaction	sig;
	int					bit_count;
	unsigned char		c;
	int					pid;
	int					i;
}	t_client;

#endif