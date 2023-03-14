/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:34:07 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/14 14:25:11 by kakumar          ###   ########.fr       */
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
	char				c;
}	t_client;

#endif